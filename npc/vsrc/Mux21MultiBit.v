module Mux21MultiBit #(
    DATA_WIDTH = 32
) (
    input wire [DATA_WIDTH-1:0] in0,
    input wire [DATA_WIDTH-1:0] in1,
    input wire Sel,
    output wire [DATA_WIDTH-1:0] Dout
);

MuxKey # (
    .NR_KEY(2),
    .KEY_LEN(1),
    .DATA_LEN(DATA_WIDTH)
  )
  MuxKey_inst (
    .out(Dout),
    .key(Sel),
    .lut({
        1'b0, in0,
        1'b1, in1
    })
  ); 
endmodule
