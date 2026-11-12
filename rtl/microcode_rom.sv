`timescale 1ns/1ps
// 12-bit address -> 32-bit microinstruction.
// Initialised from a hex file (one 32-bit word per line).
module microcode_rom #(
    parameter int DEPTH = 4096,
    parameter       INIT_FILE = ""
) (
    input  logic [11:0] addr,
    output logic [31:0] data
);

    logic [31:0] mem [0:DEPTH-1];

    initial begin
        if (INIT_FILE != "") begin
            $readmemh(INIT_FILE, mem);
        end else begin
            for (int i = 0; i < DEPTH; i++) mem[i] = 32'h0;
        end
    end

    assign data = mem[addr];

endmodule