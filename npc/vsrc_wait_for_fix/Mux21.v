module Mux21 (
    input wire in1, in2, sel,
    output wire out
);

wire [3:0] lut;
assign lut = {1'b0, in1, 
              1'b1, in2};

MuxKey # (
    .NR_KEY(2),
    .KEY_LEN(1),
    .DATA_LEN(1)
  )
  MuxKey_inst (
    .out(out),
    .key(sel),
    .lut(lut)
  ); 


endmodule
