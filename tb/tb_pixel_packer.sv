`timescale 1ns/1ps
module tb_pixel_packer;
    logic [2:0] fmt;
    logic [3:0] pos;
    logic [15:0] word, pixel_in, pixel_out, word_out;
    logic is_write;

    pixel_packer dut (.*);

    task check_read(input [2:0] f, input [3:0] p, input [15:0] w, input [15:0] exp);
        fmt = f; pos = p; word = w;
        #1;
        if (pixel_out !== exp) $error("read fmt=%0d pos=%0d word=%h -> %h, expected %h", f, p, w, pixel_out, exp);
    endtask

    task check_write(input [2:0] f, input [3:0] p, input [15:0] w, input [15:0] pix, input [15:0] exp);
        fmt = f; pos = p; word = w; pixel_in = pix;
        #1;
        if (word_out !== exp) $error("write fmt=%0d pos=%0d word=%h pix=%h -> %h, expected %h", f, p, w, pix, word_out, exp);
    endtask

    initial begin
        // 4 bpp: word = 0x0123, pos 0 -> 0, pos 1 -> 1, pos 2 -> 2, pos 3 -> 3
        check_read(3'd2, 4'd0, 16'h0123, 16'h0);
        check_read(3'd2, 4'd1, 16'h0123, 16'h1);
        check_read(3'd2, 4'd2, 16'h0123, 16'h2);
        check_read(3'd2, 4'd3, 16'h0123, 16'h3);

        // 4 bpp write: word=0xFFFF, pos=2, pixel=0xA -> 0xFFAF (pos 2 = bits 7:4? check packing)
        // packing: pos 0 = high nibble, pos 3 = low nibble
        // shift for pos 2 = (3-2)*4 = 4, mask 0x00F0, word 0xFFFF -> 0xFF0F | 0xA0 = 0xFFAF
        check_write(3'd2, 4'd2, 16'hFFFF, 16'hA, 16'hFFAF);

        // 8 bpp: word = 0xABCD, pos 0 -> 0xAB, pos 1 -> 0xCD
        check_read(3'd3, 4'd0, 16'hABCD, 16'hAB);
        check_read(3'd3, 4'd1, 16'hABCD, 16'hCD);

        // 1 bpp: word = 0x8001, pos 0 -> bit 15 = 1, pos 15 -> bit 0 = 1, pos 1 -> 0
        check_read(3'd0, 4'd0, 16'h8001, 16'h1);
        check_read(3'd0, 4'd1, 16'h8001, 16'h0);
        check_read(3'd0, 4'd15, 16'h8001, 16'h1);

        $display("tb_pixel_packer: PASS");
        $finish;
    end
endmodule
