module CPU #(
    DATA_WIDTH = 32
) (
    input wire clk,
    input wire rst
);

wire [DATA_WIDTH-1:0] PC;
wire [DATA_WIDTH-1:0] Instr;
wire PCAsrc, PCBsrc;
wire [DATA_WIDTH-1:0] Imm;
wire [DATA_WIDTH-1:0] busA, busB, busW;
wire [2:0] Branch;
wire Less, Zero;
wire [4:0] rs1, rs2, rd;
wire RegWr;
wire [6:0] op;
wire [2:0] func3;
wire [6:0] func7;
wire [2:0] ExtOp;
wire ALUAsrc;
wire [1:0] ALUBsrc;
wire [3:0] ALUctr;
wire [DATA_WIDTH-1:0] Addr;
wire MemtoReg;
wire MemWr;
wire [2:0] MemOp;
wire [DATA_WIDTH-1:0] DataIn;
wire [DATA_WIDTH-1:0] DataOut;
wire [DATA_WIDTH-1:0] ALUa, ALUb;
wire [DATA_WIDTH-1:0] ALUout;

assign DataIn = busB;
assign Addr = ALUout;

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

// 访问指令存储器
InstrMemCtrl u_InstrMemCtrl(
  .rst    (rst    ),
  .RdAddr (PC     ),
  .Instr  (Instr  )
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
    .Zero(Zero),
    .Less(Less),
    .ALUout(ALUout)
  );

// 寄存器写回来源选择模块
Mux21MultiBit  Mux21MultiBit_inst2 (
    .in0(ALUout),
    .in1(DataOut),
    .Sel(MemtoReg),
    .Dout(busW)
  );

// 访问内存
MemCtrl u_MemCtrl(
  .clk     (clk     ),
  .rst     (rst     ),
  .Addr    (Addr    ),
  .MemOp   (MemOp   ),
  .MemWr   (MemWr   ),
  .DataIn  (DataIn  ),
  .DataOut (DataOut )
);



endmodule
