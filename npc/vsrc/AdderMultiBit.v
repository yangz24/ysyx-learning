module AdderMultiBit #(DATA_WIDTH = 32)
(
    input [DATA_WIDTH-1:0] A,
    input [DATA_WIDTH-1:0] B,
    output reg [DATA_WIDTH-1:0] Dout
);

always @* begin
    Dout = A + B;
end

endmodule
