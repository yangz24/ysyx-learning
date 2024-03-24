module Mux81 #(DATA_WIDTH = 32)
(
    input wire [DATA_WIDTH-1:0] In0, In1, In2, In3, In4, In5, In6, In7,
    input wire [2:0] Sel,
    output wire [DATA_WIDTH-1:0] Dout
);

MuxKey # (
    .NR_KEY(8),
    .KEY_LEN(3),
    .DATA_LEN(DATA_WIDTH)
  )
  MuxKey_inst (
    .out(Dout),
    .key(Sel),
    .lut({
        3'b000, In0,
        3'b001, In1,
        3'b010, In2,
        3'b011, In3,
        3'b100, In4,
        3'b101, In5,
        3'b110, In6,
        3'b111, In7
    })
  );
    
endmodule
