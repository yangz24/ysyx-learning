`include "define.v"

module EXU (
    input wire clk,
    input wire rst,
    // control signals input
    input wire EXReg_ALUAsrc,
    input wire [1:0] EXReg_ALUBsrc,
    input wire [3:0] EXReg_ALUctr,
    input wire [2:0] EXReg_Branch,
    input wire EXReg_MemtoReg,
    input wire EXReg_MemWr,
    input wire EXReg_MemRd,
    input wire [2:0] EXReg_MemOp,
    input wire EXReg_RegWr, // 写寄存器使能
    // 前递
    input wire  ForwardingA,
    input wire  ForwardingB,
    input wire [`DATA_WIDTH-1:0] busW,
    // data input
    input wire [`DATA_WIDTH-1:0] EXReg_busA,
    input wire [`DATA_WIDTH-1:0] EXReg_busB,
    input wire [`ADDR_WIDTH-1:0] EXReg_Regrd, // 写寄存器地址
    input wire [`DATA_WIDTH-1:0] EXReg_Imm,
    // PC input
    input wire [`DATA_WIDTH-1:0] EXReg_PC,
    // Instr input
    input wire [`DATA_WIDTH-1:0] EXReg_Instr,
    // diffen
    input wire id_diffen,
    // controls signals output
    output wire PCsrc,
    output reg WBReg_PCsrc, // for difftest
    output reg WBReg_RegWr,
    output reg WBReg_MemtoReg,
    // data output
    output reg [`ADDR_WIDTH-1:0] WBReg_Regrd,
    output reg [`DATA_WIDTH-1:0] WBReg_ALUout,
    output reg [`DATA_WIDTH-1:0] WBReg_DataOut,
    output reg [`DATA_WIDTH-1:0] BranchPC,
    // PC output
    output reg [`DATA_WIDTH-1:0] WBReg_PC,
    // Instr output
    output reg [`DATA_WIDTH-1:0] WBReg_Instr,

    output reg ex_diffen

);

// ALU
wire [`DATA_WIDTH-1:0] ALUa, ALUb;
wire Zero, Less;
wire [`DATA_WIDTH-1:0] ALUout;

// Branch
wire [`DATA_WIDTH-1:0] PCA, PCB;
wire PCAsrc, PCBsrc;
// Memory
wire [`DATA_WIDTH-1:0] DataOut;

wire enalbe = 1;

wire [`DATA_WIDTH-1:0] newbusA;
wire [`DATA_WIDTH-1:0] newbusB;
assign newbusA = (ForwardingA == 1'b1)? busW : EXReg_busA;
assign newbusB = (ForwardingB == 1'b1)? busW : EXReg_busB;

// ALU输入选择模块
assign ALUa = EXReg_ALUAsrc? EXReg_PC : newbusA ;
assign ALUb = (EXReg_ALUBsrc == 2'b00)? newbusB :
              (EXReg_ALUBsrc == 2'b01)? EXReg_Imm :
              (EXReg_ALUBsrc == 2'b10)? 32'd4 : 0;

// ALU模块
ALU  ALU_inst (
    .A(ALUa),
    .B(ALUb),
    .ALUctr(EXReg_ALUctr),
    .Zero(Zero),
    .Less(Less),
    .ALUout(ALUout)
  );

BranchCond u_BranchCond(
  .Branch (EXReg_Branch ),
  .Less   (Less   ),
  .Zero   (Zero   ),
  .PCAsrc (PCAsrc ),
  .PCBsrc (PCBsrc ),
  .PCsrc  (PCsrc)
);

MemCtrl u_MemCtrl(
  .clk     (clk     ),
  .rst     (rst     ),
  .Addr    (ALUout    ),
  .MemOp   (EXReg_MemOp   ),
  .MemWr   (EXReg_MemWr  ),
  .MemRd   (EXReg_MemRd),
  .DataIn  (newbusB  ),
  .DataOut (DataOut )
);

assign PCA = PCAsrc ? EXReg_Imm : 32'd4;
assign PCB = PCBsrc ? newbusA : EXReg_PC;
assign BranchPC = PCA + PCB;


always @(posedge clk ) begin
  if (rst ) begin
    WBReg_RegWr <= 0;
    WBReg_Regrd <= 0;
    WBReg_MemtoReg <= 0;
    WBReg_ALUout <= 0;
    WBReg_DataOut <= 0;
    WBReg_PC <= 0;
    WBReg_Instr <= 0;
    ex_diffen <= 0;
    WBReg_PCsrc <= 0;
  end
  else if (enalbe) begin
    WBReg_RegWr <= EXReg_RegWr;
    WBReg_Regrd <= EXReg_Regrd;
    WBReg_MemtoReg <= EXReg_MemtoReg;
    WBReg_ALUout <= ALUout;
    WBReg_DataOut <= DataOut;
    WBReg_PC <= EXReg_PC;
    WBReg_Instr <= EXReg_Instr;
    ex_diffen <= id_diffen;
    WBReg_PCsrc <= PCsrc;
  end

end


endmodule