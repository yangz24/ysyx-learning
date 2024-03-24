module ALU #(DATA_WIDTH = 32) (
    input   wire [DATA_WIDTH-1:0] A,
    input   wire [DATA_WIDTH-1:0] B,
    input   wire [3:0]          ALUctr,
    output  wire                Less, 
    output  wire                Zero,    
    output  reg  [DATA_WIDTH-1:0] ALUout
);

// alu control module, generate control signals
wire [2:0] 	ALUctrl;
wire       	A_or_L;
wire       	L_or_R;
wire       	U_or_S;
wire       	Sub_or_Add;

ALUControl u_ALUControl(
    .ALUctr     	( ALUctr      ),
    .ALUctrl    	( ALUctrl     ),
    .A_or_L     	( A_or_L      ),
    .L_or_R     	( L_or_R      ),
    .U_or_S     	( U_or_S      ),
    .Sub_or_Add 	( Sub_or_Add  )
);

// Sub_or_Add signal extend to 32 bit
wire [DATA_WIDTH-1:0] Extend_op = {32{Sub_or_Add}};
// src1, src2 of adder
wire [DATA_WIDTH-1:0] A1 = A;
wire [DATA_WIDTH-1:0] B1 = B ^ Extend_op;

// addr module
wire Carry;
wire Overflow;
wire [DATA_WIDTH-1:0] Result;
Adder32 # (
    .DATA_WIDTH(DATA_WIDTH)
  )
  Adder32_inst (
    .A(A1),
    .B(B1),
    .Cin(Sub_or_Add),
    .Carry(Carry),
    .Zero(Zero),
    .Overflow(Overflow),
    .Result(Result)
  );

// 32bit BarrelShifter
wire [DATA_WIDTH-1:0] ShiftOut;
BarrelShifter  BarrelShifter_inst (
    .Din(A),
    .Shamt(B[4:0]),
    .L_or_R(L_or_R),
    .A_or_L(A_or_L),
    .Dout(ShiftOut)
  );

// mux21
wire [DATA_WIDTH-2:0] Extend_Zero = 0;
wire [DATA_WIDTH-1:0] Slt = {Extend_Zero, Less};
Mux21  Mux21_inst (
    .in1(Overflow ^ Result[DATA_WIDTH-1]),
    .in2(Sub_or_Add ^ Carry),
    .sel(U_or_S),
    .out(Less)
  );

// mux81
Mux81  Mux81_inst (
    .In0(Result),
    .In1(ShiftOut),
    .In2(Slt),
    .In3(B),
    .In4(A ^ B),
    .In5(ShiftOut),
    .In6(A | B),
    .In7(A & B),
    .Sel(ALUctrl),
    .Dout(ALUout)
  );
  
endmodule 
