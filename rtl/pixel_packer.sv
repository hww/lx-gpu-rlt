`timescale 1ns/1ps
// Unpack/pack a pixel in a 16-bit word by fmt and pos.
// fmt: 0=1bpp, 2=4bpp, 3=8bpp, 4=16bpp, 5=PASS_LO8, 6=PASS_HI8, 7=PASS16.
// pos: 0..15 (for 1bpp), 0..3 (4bpp), 0..1 (8bpp), 0 (16bpp).
module pixel_packer (
    input  logic [2:0]  fmt,
    input  logic [3:0]  pos,
    input  logic [15:0] word,
    input  logic [15:0] pixel_in,
    output logic [15:0] pixel_out,   // unpacked (read)
    output logic [15:0] word_out,    // packed   (write)
    output logic        is_write     // 1 = use word_out, 0 = use pixel_out
);

    logic [4:0]  shift;
    logic [15:0] mask;

    always_comb begin
        // defaults
        pixel_out = 16'h0;
        word_out  = word;
        is_write  = 1'b0;
        shift     = 5'd0;
        mask      = 16'hFFFF;

        case (fmt)
            3'd0: begin // 1 bpp: 16 pixels per word; pos 0 = bit 15
                shift     = 5'd15 - {1'b0, pos};
                pixel_out = 16'h0 | {15'h0, word[shift[3:0]]};
                mask      = 16'h0001 << shift;
                word_out  = (word & ~mask) | ((pixel_in & 16'h0001) << shift);
            end
            3'd1: begin // reserved: 2 bpp slot (not implemented)
                // placeholder: behave as PASS16 until 2 bpp is defined
                pixel_out = word;
                word_out  = pixel_in;
            end            
            3'd2: begin // 4 bpp: pos 0 = high nibble
                shift     = ({1'b0, 2'd3 - pos[1:0]}) * 4;
                pixel_out = 16'h0 | ((word >> shift) & 16'h000F);
                mask      = 16'h000F << shift;
                word_out  = (word & ~mask) | ((pixel_in & 16'h000F) << shift);
            end
            3'd3: begin // 8 bpp: pos 0 = high byte
                shift     = ({1'b0, 1'b1 - pos[0]}) * 8;
                pixel_out = 16'h0 | ((word >> shift) & 16'h00FF);
                mask      = 16'h00FF << shift;
                word_out  = (word & ~mask) | ((pixel_in & 16'h00FF) << shift);
            end
            3'd4: begin // 16 bpp: 1 pixel per word
                pixel_out = word;
                word_out  = pixel_in;
            end
            3'd5: begin // PASS_LO8
                pixel_out = {8'h0, word[7:0]};
                word_out  = (word & 16'hFF00) | (pixel_in & 16'h00FF);
            end
            3'd6: begin // PASS_HI8
                pixel_out = {8'h0, word[15:8]};
                word_out  = (word & 16'h00FF) | ((pixel_in & 16'h00FF) << 8);
            end
            3'd7: begin // PASS16
                pixel_out = word;
                word_out  = pixel_in;
            end
            default: begin // fmt=1 reserved
                pixel_out = word;
                word_out  = pixel_in;
            end
        endcase
    end

endmodule