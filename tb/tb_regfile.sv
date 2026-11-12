`timescale 1ns/1ps
module tb_regfile;
    logic clk = 0, rst = 1;
    logic [4:0] ra, rb, wa;
    logic [23:0] wdata, rdata_a, rdata_b;
    logic we = 0;

    regfile dut (.*);

    always #5 clk = ~clk;

    initial begin
        ra = 0; rb = 1; wa = 0; wdata = 24'h0;
        repeat (2) @(posedge clk);
        rst = 0;

        // write R0 = 0x123456
        wa = 5'd0; wdata = 24'h123456; we = 1;
        @(posedge clk);
        @(negedge clk);          // inputs change away from the posedge (no race)
        we = 0;

        // read R0 (write-first: same cycle should see new value)
        ra = 5'd0;
        #1;
        if (rdata_a !== 24'h123456) $error("R0 read = %h, expected 123456", rdata_a);

        // write R31
        wa = 5'd31; wdata = 24'hABCDEF; we = 1;
        @(posedge clk);
        @(negedge clk);          // inputs change away from the posedge (no race)
        we = 0;
        rb = 5'd31;
        #1;
        if (rdata_b !== 24'hABCDEF) $error("R31 read = %h, expected ABCDEF", rdata_b);

        $display("tb_regfile: PASS");
        $finish;
    end
endmodule
