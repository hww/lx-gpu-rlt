`timescale 1ns/1ps
module tb_alu;
    logic [4:0] op;
    logic [23:0] a, b, res;
    logic z, n, c, v;

    alu dut (.*);

    task check(input [23:0] exp_res, input exp_z, input exp_n, input exp_c, input exp_v);
        #1;
        if (res !== exp_res || z !== exp_z || n !== exp_n || c !== exp_c || v !== exp_v)
            $error("op=%0d a=%h b=%h -> res=%h z=%b n=%b c=%b v=%b, expected res=%h z=%b n=%b c=%b v=%b",
                   op, a, b, res, z, n, c, v, exp_res, exp_z, exp_n, exp_c, exp_v);
    endtask

    initial begin
        // ADD 5 + 7 = 12, C=0, V=0
        op = 5'd5; a = 24'd5; b = 24'd7;
        check(24'd12, 1'b0, 1'b0, 1'b0, 1'b0);

        // SUB 5 - 7 = 0xFFFFFE (-2), C=0 (borrow), N=1, V=0
        op = 5'd6; a = 24'd5; b = 24'd7;
        check(24'hFFFFFE, 1'b0, 1'b1, 1'b0, 1'b0);

        // ADD overflow: 0x7FFFFF + 1 = 0x800000, V=1
        op = 5'd5; a = 24'h7FFFFF; b = 24'd1;
        check(24'h800000, 1'b0, 1'b1, 1'b0, 1'b1);

        // AND 0xF0 & 0x0F = 0, Z=1
        op = 5'd1; a = 24'hF0; b = 24'h0F;
        check(24'h0, 1'b1, 1'b0, 1'b0, 1'b0);

        // MUL 1000 * 2000 = 2_000_000 = 0x1E8480
        op = 5'd12; a = 24'd1000; b = 24'd2000;
        check(24'h1E8480, 1'b0, 1'b0, 1'b0, 1'b0);

        $display("tb_alu: PASS");
        $finish;
    end
endmodule
