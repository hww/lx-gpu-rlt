`timescale 1ns/1ps
// Program counter, SHADOW, LOOP, flags, and next-PC selection.
// One instruction per cycle (the model does not simulate stalls).
module sequencer (
    input  logic        clk,
    input  logic        rst,

    // instruction fields
    input  logic [1:0]  imm_class,   // {J, I}
    input  logic [4:0]  reg_op,      // ALU op or CTRL op
    input  logic [3:0]  cond,
    input  logic        l,           // loop flag
    input  logic [11:0] imm12,       // ADDR / IMM12
    input  logic [23:0] imm24,       // LDI24

    // current flags
    input  logic        z, n, c, v,

    // outputs
    output logic [11:0] pc,
    output logic [11:0] pc_next,
    output logic [15:0] shadow,
    output logic [23:0] loop_reg,
    output logic        halted,
    output logic        error,
    output logic [11:0] error_code,

    // test-only: write loop_reg
    input  logic        loop_we,
    input  logic [23:0] loop_in
);

    // condition decode
    function automatic logic cond_true(input logic [3:0] cd,
                                       input logic zz, nn, cc, vv);
        case (cd)
            4'd0:  cond_true = 1'b1;                       // AL
            4'd1:  cond_true = zz;                         // EQ
            4'd2:  cond_true = ~zz;                        // NE
            4'd3:  cond_true = cc;                         // CS
            4'd4:  cond_true = ~cc;                        // CC
            4'd5:  cond_true = nn;                         // MI
            4'd6:  cond_true = ~nn;                        // PL
            4'd7:  cond_true = vv;                         // VS
            4'd8:  cond_true = ~vv;                        // VC
            4'd9:  cond_true = cc & ~zz;                   // HI
            4'd10: cond_true = ~cc | zz;                   // LS
            4'd11: cond_true = (nn == vv);                 // GE
            4'd12: cond_true = (nn != vv);                 // LT
            4'd13: cond_true = ~zz & (nn == vv);           // GT
            4'd14: cond_true = zz | (nn != vv);            // LE
            default: cond_true = 1'b0;
        endcase
    endfunction

    // CTRL op codes (must match gpu.h CtrlOp)
    localparam logic [4:0] C_JMP  = 5'd1;
    localparam logic [4:0] C_CALL = 5'd2;
    localparam logic [4:0] C_RET  = 5'd3;
    localparam logic [4:0] C_JMPR = 5'd4;
    localparam logic [4:0] C_HALT = 5'd5;
    localparam logic [4:0] C_IRQ  = 5'd6;

    logic is_ctrl;
    logic active;
    logic do_ctrl;
    logic [11:0] pc_next_c;

    assign is_ctrl = (imm_class == 2'b10);   // J=1, I=0
    assign active  = cond_true(cond, z, n, c, v);
    assign do_ctrl = is_ctrl && active;

    // ---- combinational next-PC ----
    always_comb begin
        pc_next_c = pc + 12'd1;

        if (do_ctrl) begin
            case (reg_op)
                C_JMP:  pc_next_c = imm12;
                C_CALL: pc_next_c = imm12;
                C_RET:  pc_next_c = shadow[11:0];
                C_JMPR: pc_next_c = 12'h0;   // filled by top
                C_HALT: pc_next_c = pc + 12'd1;
                default: ;
            endcase
        end

        // L override: loop target wins (only if count > 1)
        if (l && (loop_reg[23:12] > 12'd1))
            pc_next_c = loop_reg[11:0];
    end

    assign pc_next = pc_next_c;

    // ---- state ----
    always_ff @(posedge clk) begin
        if (rst) begin
            $display("SEQ rst: halted<=0");            
            pc         <= 12'h0;
            shadow     <= 16'h0;
            loop_reg   <= 24'h0;
            halted     <= 1'b0;
            error      <= 1'b0;
            error_code <= 12'h0;
        end else if (halted || error) begin
            // stay put
        end else begin
             $display("FF: halted=%b error=%b imm_class=%b reg_op=%d imm12=%h",
                     halted, error, imm_class, reg_op, imm12);
            pc <= pc_next_c;

            // loop register update
            if (loop_we)
                loop_reg <= loop_in;
            else if (l && (loop_reg[23:12] > 12'd1))
                loop_reg <= {loop_reg[23:12] - 12'd1, loop_reg[11:0]};

            // control side effects
            if (do_ctrl) begin
                case (reg_op)
                    C_CALL: shadow <= {4'h0, pc + 12'd1};
                    C_HALT: begin
                        if (imm12 == 12'h0) halted <= 1'b1;
                        else begin error <= 1'b1; error_code <= imm12; end
                    end
                    default: ;
                endcase
            end
        end
    end

endmodule