module PcGen #(
    DATA_WIDTH = 32
) (
    input wire clk,
    input wire rst,
    input wire PCAsrc,
    input wire PCBsrc,
    input wire [DATA_WIDTH-1:0] Imm,
    input wire [DATA_WIDTH-1:0] rs1,
    output reg [DATA_WIDTH-1:0] PC
);

parameter RESET_VAL = 32'h80000000;

wire [DATA_WIDTH-1:0] ADDa, ADDb;
wire [DATA_WIDTH-1:0] NextPC;


Mux21MultiBit  Mux21MultiBit_inst1(
    .in0(32'd4),
    .in1(Imm),
    .Sel(PCAsrc),
    .Dout(ADDa)
  );

Mux21MultiBit  Mux21MultiBit_inst2(
    .in0(PC),
    .in1(rs1),
    .Sel(PCBsrc),
    .Dout(ADDb)
  );

AdderMultiBit  AdderMultiBit_inst (
    .A(ADDa),
    .B(ADDb),
    .Dout(NextPC)
  );

always @(posedge clk ) begin
    if (rst) begin
        PC <= RESET_VAL;
    end
    else begin
        PC <= NextPC;
    end
end
    
endmodule
