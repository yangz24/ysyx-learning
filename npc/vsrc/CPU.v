module CPU #(
    DATA_WIDTH = 32
) (
    input wire clk,
    input wire rst,
    // 指令输入
    output wire [DATA_WIDTH-1:0] InstrMemRdAddr,  // 读下一条指令存储器地址
    input wire [DATA_WIDTH-1:0] Instr,   // 获取指令
    // 存储器
    output wire MemOper,
    output wire MemWrEn,
    output wire [DATA_WIDTH-1:0] MemAddr,
    // 读数据存储器
    input wire [DATA_WIDTH-1:0] MemDATAOut,    
    // 写数据存储器
    output wire [DATA_WIDTH-1:0] MemDATAIn
);

wire PCAsrc, PCBsrc;
wire [DATA_WIDTH-1:0] Imm;
wire [DATA_WIDTH-1:0] busA, busB, busW;
wire [DATA_WIDTH-1:0] PC;
wire [2:0] Branch;
wire Less = 0, Zero;
wire [4:0] rs1, rs2, rd;
wire RegWr;
wire [6:0] op;
wire [2:0] func3;
wire [6:0] func7;
wire [2:0] ExtOp;
wire ALUAsrc;
wire [1:0] ALUBsrc;
wire [3:0] ALUctr;
wire MemtoReg;
wire MemWr;
wire MemOp;
wire [DATA_WIDTH-1:0] ALUa, ALUb;
wire [DATA_WIDTH-1:0] ALUout;

assign InstrMemRdAddr = PC;
assign MemWrEn = MemWr;
assign MemOper = MemOp;
assign MemDATAIn = busB;
assign MemAddr = ALUout;

// PC生成及更新模块
PcGen  PcGen_inst (
    .clk(clk),
    .rst(rst),
    .PCAsrc(PCAsrc),
    .PCBsrc(PCBsrc),
    .Imm(Imm),
    .rs1(busA),
    .PC(PC)
  );

// 分支跳转判断模块
BranchCond  BranchCond_inst (
    .Branch(Branch),
    .Less(Less),
    .Zero(Zero),
    .PCAsrc(PCAsrc),
    .PCBsrc(PCBsrc)
  );

// 通用寄存器模块
RegisterFile # (
    .DATA_WIDTH(DATA_WIDTH)
  )
  RegisterFile_inst (
    .Wrclk(clk),
    .Ra(rs1),
    .Rb(rs2),
    .Rw(rd),
    .busW(busW),
    .RegWr(RegWr),
    .busA(busA),
    .busB(busB)
  );

// 预译码模块
PreDecoder  PreDecoder_inst (
    .Instr(Instr),
    .op(op),
    .rs1(rs1),
    .rs2(rs2),
    .rd(rd),
    .func3(func3),
    .func7(func7)
  );

// 译码模块
Decoder  Decoder_inst (
    .op(op),
    .func3(func3),
    .func7(func7),
    .ExtOp(ExtOp),
    .RegWr(RegWr),
    .ALUAsrc(ALUAsrc),
    .ALUBsrc(ALUBsrc),
    .ALUctr(ALUctr),
    .Branch(Branch),
    .MemtoReg(MemtoReg),
    .MemWr(MemWr),
    .MemOp(MemOp)
  );

// 立即数生成模块
ImmGen  ImmGen_inst (
    .Instr(Instr),
    .ExtOp(ExtOp),
    .Imm(Imm)
  );

// ALU输入选择模块
Mux21MultiBit  Mux21MultiBit_inst1 (
    .in0(busA),
    .in1(PC),
    .Sel(ALUAsrc),
    .Dout(ALUa)
  );

Mux31MultiBit  Mux31MultiBit_inst (
    .in0(busB),
    .in1(Imm),
    .in2(32'd4),
    .Sel(ALUBsrc),
    .Dout(ALUb)
  );

// ALU模块
ALU  ALU_inst (
    .A(ALUa),
    .B(ALUb),
    .ALUctr(ALUctr),
    .zero(Zero),
    .ALUout(ALUout)
  );

// 寄存器写回来源选择模块
Mux21MultiBit  Mux21MultiBit_inst2 (
    .in0(ALUout),
    .in1(MemDATAOut),
    .Sel(MemtoReg),
    .Dout(busW)
  );

endmodule
