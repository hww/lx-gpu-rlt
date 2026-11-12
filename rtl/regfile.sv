// 32 x 24 register file, 2 read ports, 1 write port, write-first.
module regfile (
    input  logic        clk,
    input  logic        rst,
    // read port A
    input  logic [4:0]  ra,
    output logic [23:0] rdata_a,
    // read port B
    input  logic [4:0]  rb,
    output logic [23:0] rdata_b,
    // write port
    input  logic        we,
    input  logic [4:0]  wa,
    input  logic [23:0] wdata
);

    logic [23:0] mem [0:31];

    always_ff @(posedge clk) begin
        if (rst) begin
            for (int i = 0; i < 32; i++) mem[i] <= 24'h0;
        end else if (we) begin
            mem[wa] <= wdata;
        end
    end

    // Read-first: reads return the stored value; a write lands on the next
    // clock. The current design never writes and reads the same register in
    // the same cycle (no pipeline), so write-first vs read-first doesn't
    // matter yet; it will if a pipeline is added.
    assign rdata_a = mem[ra];
    assign rdata_b = mem[rb];

endmodule
