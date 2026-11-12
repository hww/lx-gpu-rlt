`timescale 1ns/1ps
// 4-entry pixel buffer: SRC, DST, STM, RSV.
// Each entry: tag (16-bit word address), data (16-bit), page (8-bit),
// valid, dirty. Hit/miss handled by the caller (sequencer).
module pixel_buffer (
    input  logic        clk,
    input  logic        rst,

    // channel select (0..3)
    input  logic [1:0]  ch,

    // lookup
    input  logic [23:0] addr24,
    output logic        hit,
    output logic [15:0] rdata,
    output logic [7:0]  miss_page,     // page of the entry being evicted
    output logic [15:0] miss_tag,      // tag  of the entry being evicted
    output logic [15:0] miss_data,     // data of the entry being evicted
    output logic        miss_dirty,

    // writeback done (clears dirty on the entry)
    input  logic        wb_done,

    // fill (on miss)
    input  logic        fill_en,
    input  logic [15:0] fill_data,

    // write (on hit or after fill)
    input  logic        we,
    input  logic [15:0] wdata,

    // set_page (writeback + reset one channel)
    input  logic        set_page_en,
    input  logic [7:0]  set_page_val,

    // flush (writeback + invalidate all)
    input  logic        flush_en,

    // per-entry outputs for writeback inspection (optional)
    output logic        error
);

    // entry storage
    logic [15:0] tag   [0:3];
    logic [15:0] data  [0:3];
    logic [7:0]  page  [0:3];
    logic        valid [0:3];
    logic        dirty [0:3];

    logic [15:0] cur_tag;
    logic [7:0]  cur_page;

    assign cur_tag  = addr24[15:0];
    assign cur_page = addr24[23:16];

    always_comb begin
        hit      = valid[ch] && (tag[ch] == cur_tag) && (page[ch] == cur_page);
        rdata    = data[ch];
        miss_tag   = tag[ch];
        miss_page  = page[ch];
        miss_data  = data[ch];
        miss_dirty = dirty[ch];
    end

    integer i;
    always_ff @(posedge clk) begin
        if (rst) begin
            for (i = 0; i < 4; i++) begin
                tag[i]   <= 16'h0;
                data[i]  <= 16'h0;
                page[i]  <= 8'h0;
                valid[i] <= 1'b0;
                dirty[i] <= 1'b0;
            end
            error <= 1'b0;
        end else if (flush_en) begin
            for (i = 0; i < 4; i++) begin
                valid[i] <= 1'b0;
                dirty[i] <= 1'b0;
            end
        end else if (set_page_en) begin
            tag[ch]   <= 16'h0;
            data[ch]  <= 16'h0;
            page[ch]  <= set_page_val;
            valid[ch] <= 1'b0;
            dirty[ch] <= 1'b0;
        end else if (fill_en) begin
            tag[ch]   <= cur_tag;
            data[ch]  <= fill_data;
            page[ch]  <= cur_page;
            valid[ch] <= 1'b1;
            dirty[ch] <= 1'b0;
        end else if (we && hit) begin
            data[ch]  <= wdata;
            dirty[ch] <= 1'b1;
        end else if (wb_done) begin
            dirty[ch] <= 1'b0;
        end
    end

endmodule