`timescale 1ns/1ps
module alu (
    input  logic [4:0]  op,
    input  logic [23:0] a,
    input  logic [23:0] b,
    output logic [23:0] res,
    output logic        z,
    output logic        n,
    output logic        c,
    output logic        v
);

    logic [24:0]        sum;
    logic signed [47:0] p;
    logic [4:0]         s;
    logic signed [23:0] sa;

    always_comb begin
        // defaults
        res = a;
        c   = 1'b0;
        v   = 1'b0;
        sum = 25'h0;
        p   = 48'sh0;
        s   = 5'h0;
        sa  = 24'sh0;

        case (op)
            5'd0:  res = b;                 // MOV
            5'd1:  res = a & b;             // AND
            5'd2:  res = a | b;             // OR
            5'd3:  res = a ^ b;             // XOR
            5'd4:  res = a & ~b;            // ANDN
            5'd5: begin                     // ADD
                sum = {1'b0, a} + {1'b0, b};
                res = sum[23:0];
                c   = sum[24];
                v   = (a[23] == b[23]) && (res[23] != a[23]);
            end
            5'd6, 5'd7: begin               // SUB / CMP
                sum = {1'b0, a} - {1'b0, b};
                res = sum[23:0];
                c   = !sum[24];
                v   = (a[23] != b[23]) && (res[23] != a[23]);
            end
            5'd8: res = a & b;              // TST
            5'd9: begin                     // ROR
                s = (b[4:0] >= 5'd24) ? (b[4:0] - 5'd24) : b[4:0];
                res = (s == 0) ? a : ((a >> s) | (a << (6'd24 - {1'b0, s})));
            end
            5'd10: begin                    // SHR
                s = (b[4:0] >= 5'd24) ? 5'd23 : b[4:0];
                res = a >> s;
            end
            5'd11: begin                    // SAR
                sa = a;
                s  = (b[4:0] >= 5'd24) ? 5'd23 : b[4:0];
                res = sa >>> s;
            end
            5'd12: begin                    // MUL
                p = $signed(a) * $signed(b);
                res = p[23:0];
            end
            5'd13: begin                    // MULH
                p = $signed(a) * $signed(b);
                res = p[35:12];
            end
            default: res = a;
        endcase

        z = (res == 24'h0);
        n = res[23];
    end

endmodule