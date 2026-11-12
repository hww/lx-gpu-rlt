`timescale 1ns/1ps
module tb_sequencer;

    logic clk = 0, rst = 1;
    logic [1:0]  imm_class;
    logic [4:0]  reg_op;
    logic [3:0]  cond;
    logic        l;
    logic [11:0] imm12;
    logic [23:0] imm24;
    logic        z, n, c, v;
    logic [11:0] pc, pc_next;
    logic [15:0] shadow;
    logic [23:0] loop_reg;
    logic        halted, error;
    logic [11:0] error_code;
    logic        loop_we = 1'b0;
    logic [23:0] loop_in = 24'h0;

    sequencer dut (
        .clk(clk), .rst(rst),
        .imm_class(imm_class), .reg_op(reg_op), .cond(cond),
        .l(l), .imm12(imm12), .imm24(imm24),
        .z(z), .n(n), .c(c), .v(v),
        .pc(pc), .pc_next(pc_next), .shadow(shadow),
        .loop_reg(loop_reg), .halted(halted), .error(error),
        .error_code(error_code),
        .loop_we(loop_we), .loop_in(loop_in)
    );

    always #5 clk = ~clk;

    // CTRL op codes
    localparam logic [4:0] C_NOP  = 5'd0;
    localparam logic [4:0] C_JMP  = 5'd1;
    localparam logic [4:0] C_CALL = 5'd2;
    localparam logic [4:0] C_RET  = 5'd3;
    localparam logic [4:0] C_HALT = 5'd5;

    // one cycle: set inputs, wait posedge
    task automatic step_ctrl(input logic [4:0] op, input logic [11:0] addr,
                              input logic [3:0] cd = 4'd0);
        imm_class = 2'b10; reg_op = op; cond = cd; l = 1'b0;
        imm12 = addr; imm24 = 24'h0;
        @(posedge clk);
        #1;
    endtask

    task automatic step_loop(input logic [11:0] cnt_target);
        // set loop_reg to cnt_target, then run an L=1 word (NOP-ish)
        // We feed L=1 with reg_op=NOP, imm_class=ctrl
        imm_class = 2'b10; reg_op = C_NOP; cond = 4'd0; l = 1'b1;
        imm12 = 12'h0; imm24 = 24'h0;
        @(posedge clk);
        #1;
    endtask

    initial begin
        imm_class = 2'b10; reg_op = C_NOP; cond = 4'd0; l = 1'b0;
        imm12 = 12'h0; imm24 = 24'h0;
        z = 0; n = 0; c = 0; v = 0;

        repeat (2) @(posedge clk);
        rst = 0;
        #1;

        // ---- 1. JMP 0x10 ----
        step_ctrl(C_JMP, 12'h010);
        if (pc !== 12'h010) $error("JMP: pc=%h, expected 010", pc);

        // ---- 2. JMP with COND=EQ, Z=0 (not taken) ----
        // (cond is decoded from z/n/c/v inputs; z=0 -> EQ false)
        imm_class = 2'b10; reg_op = C_JMP; cond = 4'd1; l = 1'b0;
        imm12 = 12'h020; z = 0;
        @(posedge clk); #1;
        if (pc !== 12'h011) $error("JMP EQ (not taken): pc=%h, expected 011", pc);

        // ---- 3. JMP with COND=EQ, Z=1 (taken) ----
        imm_class = 2'b10; reg_op = C_JMP; cond = 4'd1; l = 1'b0;
        imm12 = 12'h030; z = 1;
        @(posedge clk); #1;
        if (pc !== 12'h030) $error("JMP EQ (taken): pc=%h, expected 030", pc);

        // ---- 4. CALL 0x040 ----
        z = 0;
        step_ctrl(C_CALL, 12'h040);
        if (pc !== 12'h040) $error("CALL: pc=%h, expected 040", pc);
        if (shadow[11:0] !== 12'h031) $error("CALL: shadow=%h, expected 031", shadow[11:0]);

        // ---- 5. RET ----
        step_ctrl(C_RET, 12'h0);
        if (pc !== 12'h031) $error("RET: pc=%h, expected 031", pc);

        // ---- 6. LOOP: write loop_reg, then L=1 ----
        l = 1'b0;
        loop_we = 1'b1; loop_in = {12'd3, 12'h050};
        @(posedge clk); #1;
        loop_we = 1'b0;
        @(posedge clk); #1;
        // first L=1: count=3 -> count=2, pc=0x050
        imm_class = 2'b10; reg_op = C_NOP; cond = 4'd0; l = 1'b1;
        @(posedge clk); #1;
        if (pc !== 12'h050) $error("LOOP 1: pc=%h, expected 050", pc);
        if (loop_reg[23:12] !== 12'd2) $error("LOOP 1: cnt=%0d, expected 2", loop_reg[23:12]);

        // second L=1: count=2 -> count=1, pc=0x050
        imm_class = 2'b10; reg_op = C_NOP; cond = 4'd0; l = 1'b1;
        @(posedge clk); #1;
        if (pc !== 12'h050) $error("LOOP 2: pc=%h, expected 050", pc);
        if (loop_reg[23:12] !== 12'd1) $error("LOOP 2: cnt=%0d, expected 1", loop_reg[23:12]);

        // third L=1: count=1 -> fall through
        imm_class = 2'b10; reg_op = C_NOP; cond = 4'd0; l = 1'b1;
        @(posedge clk); #1;
        if (pc !== 12'h051) $error("LOOP 3: pc=%h, expected 051 (fall through)", pc);

        // ---- 7. JMP with L=1 ----
        l = 1'b0;
        loop_we = 1'b1; loop_in = {12'd2, 12'h060};
        @(posedge clk); #1;
        loop_we = 1'b0;
        @(posedge clk); #1;
        imm_class = 2'b10; reg_op = C_JMP; cond = 4'd0; l = 1'b1;
        imm12 = 12'h070;
        @(posedge clk); #1;
        // C_JMP sets pc_next=0x070, then L overrides to 0x060 (count>1)
        $display("JMP+L: loop_reg=%h l=%b imm_class=%b reg_op=%d pc_next=%h pc=%h",
                 loop_reg, l, imm_class, reg_op, pc_next, pc);
        if (pc !== 12'h060) $error("JMP+L: pc=%h, expected 060", pc);
        if (loop_reg[23:12] !== 12'd1) $error("JMP+L: cnt=%0d, expected 1", loop_reg[23:12]);

        // ---- 8. HALT 0 ----
        step_ctrl(C_HALT, 12'h0);
        if (!halted) $error("HALT 0: not halted");

        // ---- 9. HALT X (error) ----
        // reset and test error
        reg_op = C_NOP; imm12 = 12'h0; l = 1'b0;
        rst = 1; #20; rst = 0; #1;
        $display("after reset: halted=%b error=%b", halted, error);
        step_ctrl(C_HALT, 12'h123);
        $display("HALT123: halted=%b error=%b error_code=%h imm_class=%b reg_op=%d imm12=%h",
                 halted, error, error_code, imm_class, reg_op, imm12);
        if (!error) $error("HALT 123: not error");
        if (error_code !== 12'h123) $error("HALT 123: code=%h, expected 123", error_code);

        $display("tb_sequencer: PASS");
        $finish;
    end

endmodule