`timescale 1ns/1ps
module top (
    input  logic clk,
    input  logic rst,
    output logic halted,
    output logic error
);

    // ===== microcode ROM =====
    logic [11:0] pc;
    logic [31:0] insn;
    microcode_rom #(.DEPTH(4096), .INIT_FILE("")) rom (
        .addr(pc), .data(insn)
    );

    // ===== unpack instruction =====
    logic        l, ds, f, sx;
    logic [1:0]  imm_class;
    logic [4:0]  dst, reg_op;
    logic [3:0]  cond;
    logic [5:0]  src;
    logic [11:0] imm12;
    logic [23:0] imm24;

    assign l         = insn[31];
    assign imm_class = {insn[30], insn[29]};
    assign dst       = insn[28:24];
    assign ds        = insn[23];
    assign cond      = insn[22:19];
    assign f         = insn[18];
    assign reg_op    = insn[17:13];
    assign src       = insn[12:7];
    assign imm12     = insn[11:0];
    assign imm24     = insn[23:0];
    assign sx        = insn[12];

    // ===== flags =====
    logic z_r, n_r, c_r, v_r;
    logic z, n, c, v;
    assign z = z_r; assign n = n_r; assign c = c_r; assign v = v_r;

    // ===== regfile =====
    logic [4:0]  ra, rb, wa;
    logic [23:0] rdata_a, rdata_b, wdata;
    logic        we;
    regfile rf (
        .clk(clk), .rst(rst),
        .ra(ra), .rdata_a(rdata_a),
        .rb(rb), .rdata_b(rdata_b),
        .we(we), .wa(wa), .wdata(wdata)
    );

    // ===== ALU =====
    logic [23:0] alu_a, alu_b, alu_res;
    logic        alu_z, alu_n, alu_c, alu_v;
    alu al (
        .op(reg_op), .a(alu_a), .b(alu_b),
        .res(alu_res), .z(alu_z), .n(alu_n), .c(alu_c), .v(alu_v)
    );

    // ===== sequencer =====
    logic [11:0] pc_next, error_code;
    logic [15:0] shadow;
    logic [23:0] loop_reg;
    sequencer seq (
        .clk(clk), .rst(rst),
        .imm_class(imm_class), .reg_op(reg_op), .cond(cond),
        .l(l), .imm12(imm12), .imm24(imm24),
        .z(z_r), .n(n_r), .c(c_r), .v(v_r),
        .pc(pc), .pc_next(pc_next), .shadow(shadow),
        .loop_reg(loop_reg), .halted(halted), .error(error),
        .error_code(error_code),
        .loop_we(loop_we), .loop_in(loop_in)
    );

    // ===== channel state =====
    logic [2:0]  ch_mode [0:3];   // fmt per channel
    logic [7:0]  ch_page [0:3];
    logic [23:0] ch_idx  [0:3];   // pixel index / stream pointer
    logic [23:0] ch_step [0:3];   // signed step

    // ===== pixel_buffer =====
    logic [1:0]  pb_ch;
    logic [23:0] pb_addr;
    logic        pb_hit;
    logic [15:0] pb_rdata;
    logic [7:0]  pb_miss_page;
    logic [15:0] pb_miss_tag, pb_miss_data;
    logic        pb_miss_dirty;
    logic        pb_wb_done;
    logic        pb_fill_en;
    logic [15:0] pb_fill_data;
    logic        pb_we;
    logic [15:0] pb_wdata;
    logic        pb_set_page_en;
    logic [7:0]  pb_set_page_val;
    logic        pb_flush_en;
    logic        pb_error;

    pixel_buffer pb (
        .clk(clk), .rst(rst),
        .ch(pb_ch), .addr24(pb_addr),
        .hit(pb_hit), .rdata(pb_rdata),
        .miss_page(pb_miss_page), .miss_tag(pb_miss_tag),
        .miss_data(pb_miss_data), .miss_dirty(pb_miss_dirty),
        .wb_done(pb_wb_done),
        .fill_en(pb_fill_en), .fill_data(pb_fill_data),
        .we(pb_we), .wdata(pb_wdata),
        .set_page_en(pb_set_page_en), .set_page_val(pb_set_page_val),
        .flush_en(pb_flush_en),
        .error(pb_error)
    );

    // ===== addr_packer =====
    logic [23:0] ap_idx;
    logic [7:0]  ap_page;
    logic [2:0]  ap_fmt;
    logic [23:0] ap_addr;
    logic [3:0]  ap_pos;
    addr_packer ap (
        .idx(ap_idx), .page(ap_page), .fmt(ap_fmt),
        .addr24(ap_addr), .pos(ap_pos)
    );

    // ===== pixel_packer (read) =====
    logic [2:0]  pp_fmt_r;
    logic [3:0]  pp_pos_r;
    logic [15:0] pp_word_r;
    logic [15:0] pp_pix_r;
    logic [15:0] pp_word_w_unused;
    logic        pp_is_write_unused;
    pixel_packer ppr (
        .fmt(pp_fmt_r), .pos(pp_pos_r), .word(pp_word_r),
        .pixel_in(16'h0),
        .pixel_out(pp_pix_r), .word_out(pp_word_w_unused),
        .is_write(pp_is_write_unused)
    );

    // ===== pixel_packer (write) =====
    logic [2:0]  pp_fmt_w;
    logic [3:0]  pp_pos_w;
    logic [15:0] pp_word_w;
    logic [15:0] pp_pix_w;
    logic [15:0] pp_pix_w_unused;
    logic [15:0] pp_word_w_out;
    logic        pp_is_write_w;
    pixel_packer ppw (
        .fmt(pp_fmt_w), .pos(pp_pos_w), .word(pp_word_w),
        .pixel_in(pp_pix_w),
        .pixel_out(pp_pix_w_unused), .word_out(pp_word_w_out),
        .is_write(pp_is_write_w)
    );

    // ===== operand mux =====
    logic [5:0]  dst_code, src_code;
    assign dst_code = {ds, dst};
    assign src_code = src;

    // special operand read
    logic [23:0] sp_rd;
    logic [23:0] op_a, op_b;

    // special operand write strobes
    logic        sp_we;
    logic [5:0]  sp_wcode;
    logic [23:0] sp_wdata;

    // ===== read special operand =====
    always_comb begin
        // defaults
        sp_rd      = 24'h0;
        pb_ch      = 2'd0;
        pb_addr    = 24'h0;
        pb_we      = 1'b0;
        pb_wdata   = 16'h0;
        pb_set_page_en = 1'b0;
        pb_set_page_val = 8'h0;
        pb_flush_en = 1'b0;
        pb_wb_done  = 1'b0;
        pb_fill_en  = 1'b0;
        pb_fill_data = 16'h0;
        ap_idx  = 24'h0;
        ap_page = 8'h0;
        ap_fmt  = 3'd0;
        pp_fmt_r = 3'd0;
        pp_pos_r = 4'd0;
        pp_word_r = 16'h0;
        pp_fmt_w = 3'd0;
        pp_pos_w = 4'd0;
        pp_word_w = 16'h0;
        pp_pix_w = 16'h0;

        // special writes (combinational strobes)
        if (!is_ctrl && !is_ldi && dst_code[5]) begin
            case (dst_code)
                6'd44: begin pb_set_page_en = 1'b1; pb_set_page_val = alu_res[7:0]; end
                6'd50: begin pb_set_page_en = 1'b1; pb_set_page_val = alu_res[7:0]; end
                6'd56: begin pb_set_page_en = 1'b1; pb_set_page_val = alu_res[7:0]; end
                6'd57: pb_flush_en = 1'b1;
                default: ;
            endcase
        end

        case (src_code)
            // ZERO
            6'd32: sp_rd = 24'h0;
            // FLAGS
            6'd33: sp_rd = {20'h0, v, c, n, z};
            // SHADOW
            6'd34: sp_rd = {8'h0, shadow};
            // LOOP
            6'd35: sp_rd = loop_reg;
            // BUSY_SRC/DST/STM — model: 0
            6'd36, 6'd37, 6'd38: sp_rd = 24'h0;
            // SRC.IDX
            6'd39: sp_rd = ch_idx[0];
            // SRC.PIX — read pixel, advance IDX
            6'd40: begin
                ap_idx  = ch_idx[0];
                ap_page = ch_page[0];
                ap_fmt  = ch_mode[0];
                pb_ch   = 2'd0;
                pb_addr = ap_addr;
                pp_fmt_r = ch_mode[0];
                pp_pos_r = ap_pos;
                pp_word_r = pb_rdata;
                sp_rd = {8'h0, pp_pix_r};
                // advance IDX by STEP
                // (handled in always_ff on sp_we? no — read side advances)
            end
            // SRC.W16
            6'd41: begin
                ap_idx  = 24'h0;
                pb_ch   = 2'd0;
                pb_addr = {ch_page[0], ch_idx[0][15:0]} << 1;
                sp_rd = {8'h0, pb_rdata};
            end
            // SRC.STEP
            6'd42: sp_rd = ch_step[0];
            // SRC.MODE
            6'd43: sp_rd = {21'h0, ch_mode[0]};
            // SRC.PAGE
            6'd44: sp_rd = {16'h0, ch_page[0]};
            // DST.IDX
            6'd45: sp_rd = ch_idx[1];
            // DST.PIX (read: no IDX change)
            6'd46: begin
                ap_idx  = ch_idx[1];
                ap_page = ch_page[1];
                ap_fmt  = ch_mode[1];
                pb_ch   = 2'd1;
                pb_addr = ap_addr;
                pp_fmt_r = ch_mode[1];
                pp_pos_r = ap_pos;
                pp_word_r = pb_rdata;
                sp_rd = {8'h0, pp_pix_r};
            end
            // DST.W16
            6'd47: begin
                pb_ch   = 2'd1;
                pb_addr = {ch_page[1], ch_idx[1][15:0]} << 1;
                sp_rd = {8'h0, pb_rdata};
            end
            // DST.STEP
            6'd48: sp_rd = ch_step[1];
            // DST.MODE
            6'd49: sp_rd = {21'h0, ch_mode[1]};
            // DST.PAGE
            6'd50: sp_rd = {16'h0, ch_page[1]};
            // STM.PTR
            6'd51: sp_rd = ch_idx[2];
            // STM.W16
            6'd52: begin
                pb_ch   = 2'd2;
                pb_addr = {ch_page[2], ch_idx[2][15:0]} << 1;
                sp_rd = {8'h0, pb_rdata};
            end
            // STM.W24
            6'd53: begin
                pb_ch   = 2'd2;
                pb_addr = {ch_page[2], ch_idx[2][15:0]} << 1;
                sp_rd = {8'h0, pb_rdata};  // only low 16 here; upper handled by STEP
            end
            // STM.STEP
            6'd54: sp_rd = ch_step[2];
            // STM.MODE
            6'd55: sp_rd = {21'h0, ch_mode[2]};
            // STM.PAGE
            6'd56: sp_rd = {16'h0, ch_page[2]};
            // FLUSH
            6'd57: sp_rd = 24'h0;
            // STM.PIX
            6'd58: begin
                ap_idx  = ch_idx[2];
                ap_page = ch_page[2];
                ap_fmt  = ch_mode[2];
                pb_ch   = 2'd2;
                pb_addr = ap_addr;
                pp_fmt_r = ch_mode[2];
                pp_pos_r = ap_pos;
                pp_word_r = pb_rdata;
                sp_rd = {8'h0, pp_pix_r};
            end
            default: sp_rd = 24'h0;
        endcase
    end

    // ===== operand read mux =====
    always_comb begin
        if (dst_code[5] == 1'b0) begin
            ra  = dst_code[4:0];
            op_a = rdata_a;
        end else begin
            ra  = 5'd0;
            op_a = sp_rd;
        end

        if (imm_class == 2'b00) begin
            if (src_code[5] == 1'b0) begin
                rb  = src_code[4:0];
                op_b = rdata_b;
            end else begin
                rb  = 5'd0;
                op_b = sp_rd;
            end
        end else begin
            rb  = 5'd0;
            op_b = sx && imm12[11] ? {12'hFFF, imm12} : {12'h000, imm12};
        end
    end

    assign alu_a = (imm_class == 2'b01) ? 24'h0 : op_a;
    assign alu_b = op_b;

    // ===== write-back to regfile =====
    logic do_write, is_ctrl, is_cmp_tst, is_ldi;
    assign is_ctrl    = (imm_class == 2'b10);
    assign is_ldi     = (imm_class == 2'b01);
    assign is_cmp_tst = (reg_op == 5'd7) || (reg_op == 5'd8);

    always_comb begin
        we    = 1'b0;
        wa    = 5'd0;
        wdata = 24'h0;

        if (!is_ctrl && !is_ldi) begin
            if (!is_cmp_tst && dst_code[5] == 1'b0) begin
                we    = 1'b1;
                wa    = dst_code[4:0];
                wdata = alu_res;
            end
        end else if (is_ldi && !dst_code[5]) begin
            we    = 1'b1;
            wa    = dst;
            wdata = imm24;
        end
    end

    // ===== special operand write (sp_we/sp_wcode/sp_wdata) =====
    // set by the sequencer's CTRL_OP for C_IRQ etc.; here only MOV special writes.
    // The actual "is this a special write" decision: dst_code[5] == 1 && !is_ctrl && !is_ldi
    logic sp_write;
    assign sp_write = (!is_ctrl && !is_ldi && dst_code[5]);
    assign sp_wcode = dst_code;
    assign sp_wdata = alu_res;


    // ===== channel state update (always_ff) =====
    always_ff @(posedge clk) begin
        if (rst) begin
            for (int i = 0; i < 4; i++) begin
                ch_mode[i] <= 3'd0;
                ch_page[i] <= 8'd0;
                ch_idx[i]  <= 24'd0;
                ch_step[i] <= 24'd0;
            end
            z_r <= 0; n_r <= 0; c_r <= 0; v_r <= 0;
        end else begin
            // flags update
            if (!is_ctrl) begin
                if (f || is_cmp_tst) begin
                    z_r <= alu_z; n_r <= alu_n; c_r <= alu_c; v_r <= alu_v;
                end
            end

            // special writes
            if (sp_write) begin
                case (sp_wcode)
                    // SRC.STEP
                    6'd42: ch_step[0] <= sp_wdata;
                    // SRC.MODE
                    6'd43: ch_mode[0] <= sp_wdata[2:0];
                    // SRC.PAGE
                    6'd44: ch_page[0] <= sp_wdata[7:0];
                    // DST.STEP
                    6'd48: ch_step[1] <= sp_wdata;
                    // DST.MODE
                    6'd49: ch_mode[1] <= sp_wdata[2:0];
                    // DST.PAGE
                    6'd50: ch_page[1] <= sp_wdata[7:0];
                    // STM.STEP
                    6'd54: ch_step[2] <= sp_wdata;
                    // STM.MODE
                    6'd55: ch_mode[2] <= sp_wdata[2:0];
                    // STM.PAGE
                    6'd56: ch_page[2] <= sp_wdata[7:0];
                    // SRC.IDX (set)
                    6'd39: ch_idx[0] <= sp_wdata;
                    // DST.IDX (set)
                    6'd45: ch_idx[1] <= sp_wdata;
                    // STM.PTR (set)
                    6'd51: ch_idx[2] <= sp_wdata;
                    default: ;
                endcase
            end

            // PIX / W16 writes advance IDX
            // (handled in read path below, but real pixel write must be here)
            // Note: this skeleton does not complete the read-modify-write for DST.PIX
            //       because pixel_buffer needs fill/writeback sequencing. That's the
            //       next step (top v4).
        end
    end

    // ===== placeholder for loop_we/loop_in =====
    logic        loop_we;
    logic [23:0] loop_in;
    assign loop_we = 1'b0;
    assign loop_in = 24'h0;

endmodule