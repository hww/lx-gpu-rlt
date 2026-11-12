`timescale 1ns/1ps
// Pixel index + page + fmt -> word address + pos.
// addr24 = (page << 16) | (word_offset << 1)
// word_offset = idx >> shift, pos = idx & mask
// fmt: 0=1bpp (shift 4), 2=4bpp (shift 2), 3=8bpp (shift 1),
//      4=16bpp (shift 0), 5/6/7=PASS (shift 0)
module addr_packer (
    input  logic [23:0] idx,       // pixel index inside the page
    input  logic [7:0]  page,      // high 8 bits of addr24
    input  logic [2:0]  fmt,
    output logic [23:0] addr24,
    output logic [3:0]  pos
);

    logic [2:0]  shift;
    logic [3:0]  mask;
    logic [23:0] word_offset;

    always_comb begin
        case (fmt)
            3'd0: begin shift = 3'd4; mask = 4'hF; end // 1 bpp
            3'd2: begin shift = 3'd2; mask = 4'h3; end // 4 bpp
            3'd3: begin shift = 3'd1; mask = 4'h1; end // 8 bpp
            default: begin shift = 3'd0; mask = 4'h0; end // 16bpp / PASS
        endcase

        word_offset = idx >> shift;
        addr24      = ({16'h0, page} << 16) | (word_offset << 1);
        pos         = idx[3:0] & mask;
    end

endmodule