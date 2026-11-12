`timescale 1ns/1ps
module tb_top;

    logic clk = 0, rst = 1;
    logic halted, error;

    top dut (.clk(clk), .rst(rst), .halted(halted), .error(error));

    always #5 clk = ~clk;

    // ----- instruction packer (matches MicroWord::pack in gpu.cpp) -----
    function automatic logic [31:0] pack_insn(
        input logic        l,
        input logic [1:0]  imm_class,   // {J, I}
        input logic [4:0]  dst,
        input logic        ds,
        input logic [3:0]  cond,
        input logic        f,
        input logic [4:0]  op,
        input logic        sx,
        input logic [11:0] imm12,
        input logic [5:0]  src,
        input logic [23:0] imm24
    );
        logic [31:0] v;
        v = {l, imm_class, dst, ds, cond, f, op, sx, imm12};
        // reg-reg / ctrl: src in [12:7]
        if (imm_class == 2'b00 || imm_class == 2'b10)
            v = (v & ~32'h1F80) | ({26'h0, src} << 7);
        // LDI24: imm24 in [23:0], keep [31:24]
        if (imm_class == 2'b01)
            v = (v & 32'hFF00_0000) | {8'h0, imm24};
        pack_insn = v;
    endfunction

    // shortcuts
    function automatic logic [31:0] I_reg(
        input logic [4:0]  dst,
        input logic [5:0]  src,
        input logic [4:0]  op,
        input logic [3:0]  cond = 4'd0,
        input logic        f    = 1'b0,
        input logic        l    = 1'b0
    );
        I_reg = pack_insn(l, 2'b00, dst, 1'b0, cond, f, op, 1'b0, 12'h0, src, 24'h0);
    endfunction

    function automatic logic [31:0] I_imm(
        input logic [4:0]  dst,
        input logic [11:0] imm,
        input logic [4:0]  op,
        input logic [3:0]  cond = 4'd0,
        input logic        f    = 1'b0,
        input logic        l    = 1'b0,
        input logic        sx   = 1'b0
    );
        I_imm = pack_insn(l, 2'b11, dst, 1'b0, cond, f, op, sx, imm, 6'h0, 24'h0);
    endfunction

    function automatic logic [31:0] I_ldi24(
        input logic [4:0]  dst,
        input logic [23:0] imm24,
        input logic        l = 1'b0
    );
        I_ldi24 = pack_insn(l, 2'b01, dst, 1'b0, 4'd0, 1'b0, 5'd0, 1'b0, 12'h0, 6'h0, imm24);
    endfunction

    function automatic logic [31:0] I_ctrl(
        input logic [4:0]  op,
        input logic [11:0] addr,
        input logic [3:0]  cond = 4'd0
    );
        I_ctrl = pack_insn(1'b0, 2'b10, 5'd0, 1'b0, cond, 1'b0, op, 1'b0, addr, 6'h0, 24'h0);
    endfunction

    // ----- test program -----
    // 0: MOV R0, #5       (reg-imm12, op=MOV, imm=5)
    // 1: LDI24 R1, 0x123456
    // 2: MOV R2, R0        (reg-reg, op=MOV, src=R0)
    // 3: CMP R2, R1        (op=CMP)
    // 4: HALT 0
    initial begin
        dut.rom.mem[0] = I_imm(5'd0, 12'd5, 5'd0);                  // MOV R0, #5
        dut.rom.mem[1] = I_ldi24(5'd1, 24'h123456);                 // LDI24 R1
        dut.rom.mem[2] = I_reg(5'd2, 6'd0, 5'd0);                   // MOV R2, R0
        dut.rom.mem[3] = I_reg(5'd2, 6'd1, 5'd7);                   // CMP R2, R1
        dut.rom.mem[4] = I_ctrl(5'd5, 12'h0);                       // HALT 0

        repeat (2) @(posedge clk);
        rst = 0;

        // run until halted (max 100 cycles)
        begin : run_loop
            repeat (100) begin
                @(posedge clk);
                if (halted) disable run_loop;
            end
        end

        if (dut.rf.mem[0] !== 24'd5)
            $error("R0 = %h, expected 5", dut.rf.mem[0]);
        if (dut.rf.mem[1] !== 24'h123456)
            $error("R1 = %h, expected 123456", dut.rf.mem[1]);
        if (dut.rf.mem[2] !== 24'd5)
            $error("R2 = %h, expected 5", dut.rf.mem[2]);
        if (!halted)
            $error("CPU not halted");
        if (error)
            $error("CPU error");

        $display("tb_top: PASS");
        $finish;
    end

endmodule