module Mux31MultiBit #(
    DATA_WIDTH = 32
) (
    input wire [DATA_WIDTH-1:0] in0,
    input wire [DATA_WIDTH-1:0] in1,
    input wire [DATA_WIDTH-1:0] in2,
    input wire [1:0] Sel,
    output wire [DATA_WIDTH-1:0] Dout
);

MuxKey # (
    .NR_KEY(3),
    .KEY_LEN(2),
    .DATA_LEN(DATA_WIDTH)
  )
  MuxKey_inst (
    .out(Dout),
    .key(Sel),
    .lut({
        2'b00, in0,
        2'b01, in1,
        2'b10, in2
    })
  ); 
endmodule
