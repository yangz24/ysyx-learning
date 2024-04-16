/* width */
`define DATA_WIDTH 32 // data width
`define ADDR_WIDTH 5 // addr width

/* pipeline registers */
typedef struct {
    logic [`DATA_WIDTH-1:0] PC;
    logic [`DATA_WIDTH-1:0] Instr;
} type_if_id_reg;

typedef struct {
    logic [`DATA_WIDTH-1:0] 
}

/* control singals */

// Register Write EN
`define REG_WRITE_EN    1'b1        // Enable register write
`define REG_WRITE_DIS   1'b0       // Disable register write
`define REG_VALID   1'b1        // Valid reg
`define REG_INVALID 1'b0        // Invalid reg

// imm type
`define EXTOP_LENGTH 3  // ExtOP length
`define EXTOP_DEFAULT 3'b111 // no type
`define EXTOP_I     3'b000 // immi
`define EXTOP_U     3'b001 // immu
`define EXTOP_S     3'b010 // imms
`define EXTOP_B     3'b011 // immb
`define EXTOP_J     3'b100 // immj

// ALU control signals
`define ALU_CTRL_LENGTH   4          // Length of signal ALUctr
`define ALU_CTRL_DEFAULT  4'b1111    // ALUctr default value, do nothing
`define ALU_CTRL_ADD      4'b0000    // ALU add
`define ALU_CTRL_SUB      4'b1000    // ALU sub
`define ALU_CTRL_SLT      4'b0001    // ALU shift left
`define ALU_CTRL_LESS     4'b0010    // ALU less than
`define ALU_CTRL_LESSU    4'b1010    // ALU unsinged less than 
`define ALU_CTRL_SRCB     4'b0011    // ALU output B source
`define ALU_CTRL_XOR      4'b0100    // ALU xor
`define ALU_CTRL_SLR      4'b0101    // ALU shift logic right
`define ALU_CTRL_SAR      4'b1101    // ALU shift arithmetic right
`define ALU_CTRL_OR       4'b0110    // ALU or
`define ALU_CTRL_AND      4'b0111    // ALU and

// ALU source control signals
`define ALU_ASRC_RS1 1'b0 // alu input A source from rs1
`define ALU_ASRC_PC  1'b1 // alu input A source from PC 

`define ALU_BSRC_RS2 2'b00 // alu input B source from rs2
`define ALU_BSRC_IMM 2'b01 // alu input B source from imm
`define ALU_BSRC_CONST4 2'b10 // alu input B source from constant 4


// Branch control signals
`define BRANCH_NONE 3'b000  // not a jump instr
`define BRANCH_NOCOND_PC 3'b001 // no condition jump PC dst
`define BRANCH_NOCOND_RS1 3'b010 // no condition jump rs1 dst
`define BRANCH_COND_EQ 3'b100 // condition jump when equal
`define BRANCH_COND_NOTEQ 3'b101 // condition jump when not equal
`define BRANCH_COND_LESS 3'b110 // condition jump when less than
`define BRANCH_COND_GREQ 3'b111 // condition jump when great than or equal

`define PC_ASRC_CONST4 1'b0 // PCAsrc use 4
`define PC_ASRC_IMM // PCAsrc use imm

`define PC_BSRC_PC 1'b0 // PCBsrc use PC
`define PC_BSRC_RS1 1'b1 // PCBsrc use rs1

// Memory operation
`define MEMOP_DEFAULT 3'b111 // do nothing
`define MEMOP_BYTE 3'b000 // r/w 1 signed byte
`define MEMOP_HALFWORD 3'b001 // r/w 2 signed byte
`define MEMOP_BYTE_U 3'b100 // r/w 1 unsigned byte
`define MEMOP_HALFWORD_U 3'b101 // r/w 2 unsigned byte
`define MEMOP_WORD 3'b010 // r/w 4 byte