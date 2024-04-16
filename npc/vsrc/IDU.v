`include "define.v"

module IDU (
    input wire clk,
    input wire rst,
    // PC input
    input wire [`DATA_WIDTH-1:0] IDReg_PC,
    // Instr input
    input wire [`DATA_WIDTH-1:0] IDReg_Instr,
    // predecoder 
    input wire [`OPCODE_WIDTH-1:0]  IDReg_op,
    input wire [`ADDR_WIDTH-1:0]    IDReg_rs1,
    input wire [`ADDR_WIDTH-1:0]    IDReg_rs2,
    input wire [`ADDR_WIDTH-1:0]    IDReg_Regrd,
    input wire [`FUNC3_WIDTH-1:0]   IDReg_Func3,
    input wire [`FUNC7_WIDTH-1:0]   IDReg_Func7, 
    // 写回阶段返回
    input wire HoldOnRegWr, // 写回阶段返回的写寄存器使能 
    input wire [`ADDR_WIDTH-1:0] Rw, // 写回阶段写寄存器地址
    input wire [`DATA_WIDTH-1:0] busW, // 写回阶段返回的写寄存器数据
    // 冒险检测
    // input wire ClearCtr,
    // 分支预测
    input wire BPUClearCtr,
    // diffen
    input wire if_diffen,
    // control signals output 
    output reg EXReg_ALUAsrc,
    output reg [1:0] EXReg_ALUBsrc,
    output reg [3:0] EXReg_ALUctr,
    output reg [2:0] EXReg_Branch,
    output reg EXReg_RegWr, 
    output reg EXReg_MemtoReg,
    output reg EXReg_MemWr,
    output reg EXReg_MemRd,
    output reg [2:0] EXReg_MemOp,
    // data output
    output reg [`DATA_WIDTH-1:0] EXReg_busA,
    output reg [`DATA_WIDTH-1:0] EXReg_busB,
    output reg [`ADDR_WIDTH-1:0] EXReg_Regrd, 
    output reg [`ADDR_WIDTH-1:0] EXReg_Regrs1,
    output reg [`ADDR_WIDTH-1:0] EXReg_Regrs2,
    output reg [`DATA_WIDTH-1:0] EXReg_Imm,
    // PC output
    output reg [`DATA_WIDTH-1:0] EXReg_PC,
    // Instr output
    output reg [`DATA_WIDTH-1:0] EXReg_Instr,

    output reg id_diffen
);

// control signals
wire [2:0] ExtOp; // only used in IDU
wire  RegWr;  
wire  ALUAsrc;
wire [1:0] ALUBsrc;
wire [3:0] ALUctr;
wire [2:0] Branch;
wire  MemtoReg;
wire  MemWr;
wire [2:0] MemOp;
wire MemRd;
assign MemRd = (IDReg_op == 7'b0000011)? 1 : 0;
// data 
wire [`DATA_WIDTH-1:0] busA;
wire [`DATA_WIDTH-1:0] busB;


wire  newALUAsrc ;
wire [1:0] newALUBsrc ;
wire [3:0] newALUctr ;
wire [2:0] newBranch ;
wire  newRegWr  ;
wire [2:0] newMemOp  ;
wire  newMemtoReg;
wire  newMemWr  ;
wire  newMemRd  ;
wire [2:0] newExtOp;

wire [`DATA_WIDTH-1:0] Imm;



wire enable = 1;

Decoder u_Decoder(
    .op       (IDReg_op       ),
    .func3    (IDReg_Func3    ),
    .func7    (IDReg_Func7    ),
    .ExtOp    (ExtOp    ),
    .RegWr    (RegWr    ),
    .ALUAsrc  (ALUAsrc  ),
    .ALUBsrc  (ALUBsrc  ),
    .ALUctr   (ALUctr   ),
    .Branch   (Branch   ),
    .MemtoReg (MemtoReg ),
    .MemWr    (MemWr    ),
    .MemOp    (MemOp    )
);

RegisterFile u_RegisterFile(
    .Wrclk (clk ),
    .Ra    (IDReg_rs1   ),
    .Rb    (IDReg_rs2   ),
    .Rw    (Rw ),
    .busW  (busW  ),
    .RegWr (HoldOnRegWr ),
    .busA  (busA  ),
    .busB  (busB  )
);

ImmGen u_ImmGen(
    .Instr (IDReg_Instr ),
    .ExtOp (newExtOp),
    .Imm   (Imm   )
);

assign newALUAsrc =   ALUAsrc;  //                 (ClearCtr )? 0 : ALUAsrc;
assign newALUBsrc =   ALUBsrc;  //                 (ClearCtr )? 0 : ALUBsrc;
assign newALUctr =    ALUctr;   //                 (ClearCtr )? 0 : ALUctr;
assign newBranch =    Branch;   //                 (ClearCtr )? 0 : Branch;
assign newRegWr =     RegWr;    //                 (ClearCtr )? 0 : RegWr;
assign newMemOp =     MemOp;    //                 (ClearCtr )? 0 : MemOp;
assign newMemtoReg =  MemtoReg; //                 (ClearCtr )? 0 : MemtoReg;
assign newMemWr =     MemWr;    //                 (ClearCtr )? 0 : MemWr;
assign newMemRd =     MemRd;    //                 (ClearCtr )? 0 : MemRd;
assign newExtOp =     ExtOp;    //                 (ClearCtr )? 0 : ExtOp;

always @(posedge clk ) begin
    if (rst | BPUClearCtr) begin
        EXReg_ALUAsrc <= 0;
        EXReg_ALUBsrc <= 0;
        EXReg_ALUctr <= 0;
        EXReg_Branch <= 0;
        EXReg_RegWr <= 0;
        EXReg_MemOp <= 0;
        EXReg_MemtoReg <= 0;
        EXReg_MemWr <= 0;
        EXReg_MemRd <= 0;
        EXReg_busA <= 0;
        EXReg_busB <= 0;
        EXReg_Regrd <= 0;
        EXReg_Regrs1 <= 0;
        EXReg_Regrs2 <= 0;
        EXReg_Imm <= 0;
        EXReg_PC <= 0;
        EXReg_Instr <= 0;
        id_diffen <= 0;
    end
    else if (enable) begin
        EXReg_ALUAsrc <= newALUAsrc;
        EXReg_ALUBsrc <= newALUBsrc;
        EXReg_ALUctr <= newALUctr;
        EXReg_Branch <= newBranch;
        EXReg_RegWr <= newRegWr;
        EXReg_MemOp <= newMemOp;
        EXReg_MemtoReg <= newMemtoReg;
        EXReg_MemWr <= newMemWr;
        EXReg_MemRd <= newMemRd;
        EXReg_busA <= busA;
        EXReg_busB <= busB;
        EXReg_Regrd <= IDReg_Regrd;
        EXReg_Regrs1 <= IDReg_rs1;
        EXReg_Regrs2 <= IDReg_rs2;
        EXReg_Imm <= Imm;
        EXReg_PC <= IDReg_PC;
        EXReg_Instr <= IDReg_Instr;
        id_diffen <= if_diffen;
    end

end


endmodule