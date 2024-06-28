/******************************************** data width ********************************************/
`define DATA_WIDTH 32                                               // data width

`define DATA_WIDTH_1 31                                    // data width minus 1

`define INSTR_WIDTH 32                                              // instruction width

/******************************************** PC reset value ********************************************/
`define PC_WIDTH 32                                                  // PC width

`define PCStart `PC_WIDTH'h80000000

`define PC_add_4 `PC_WIDTH'd4

/******************************************** Instruction  ********************************************/
`define NOP_INSTR `INSTR_WIDTH'h00000000                               // NOP instruction
/******************************************** control signals ********************************************/

`define FUNC3_LENGTH 3                                               // Function3 length
`define FUNC3_ADD `FUNC3_LENGTH'b000                                 // Function3 addr
`define FUNC3_LEFT_SHIFT `FUNC3_LENGTH'b001                            // Function3 left shift
`define FUNC3_LESS_THAN_SET `FUNC3_LENGTH'b010                        // Function3 less than set
`define FUNC3_LESS_THAN_U_SET `FUNC3_LENGTH'b011                      // Function3 unsigned less than set
`define FUNC3_XOR `FUNC3_LENGTH'b100                                 // Function3 xor
`define FUNC3_RIGHT_SHIFT `FUNC3_LENGTH'b101                          // Function3 right shift
`define FUNC3_OR `FUNC3_LENGTH'b110                                  // Function3 or
`define FUNC3_AND `FUNC3_LENGTH'b111                                 // Function3 and

// only seconde highest bit func7[5] is useful 
`define FUNC7_LENGTH 7                                               // Function7 length
`define FUNC7_5_SUB_OR_ARITH 1'b1                                    // func7[5] is 1 for sub or arith
`define FUNC7_5_ADD_OR_LOGIC 1'b0                                    // func7[5] is 0 for add or logic

`define OPCODE_LENGTH 7                                              // Opcode length
`define OPCODE_DEFAULT `OPCODE_LENGTH'd0                             // invalid instruction
`define OPCODE_I_INT     `OPCODE_LENGTH'b0010011                       // I type instruction
`define OPCODE_I_LOAD    `OPCODE_LENGTH'b0000011                         // I type instruction
`define OPCODE_I_JALR    `OPCODE_LENGTH'b1100111                         // I type instruction
`define OPCODE_S     `OPCODE_LENGTH'b0100011                                // S type instruction
`define OPCODE_B     `OPCODE_LENGTH'b1100011                                // B type instruction
`define OPCODE_U_LUI     `OPCODE_LENGTH'b0110111                           // U type instruction
`define OPCODE_U_AUIPC   `OPCODE_LENGTH'b0010111                           // U type instruction
`define OPCODE_J     `OPCODE_LENGTH'b1101111                                // J type instruction
`define OPCODE_R     `OPCODE_LENGTH'b0110011                                // R type instruction

// imm type
`define EXTOP_LENGTH 3                                              // ExtOP length
`define EXTOP_DEFAULT `EXTOP_LENGTH'd0  // invalid                                      // no type
`define EXTOP_I     `EXTOP_LENGTH'd1                                          // immi
`define EXTOP_U     `EXTOP_LENGTH'd2                                          // immu
`define EXTOP_S     `EXTOP_LENGTH'd3                                          // imms
`define EXTOP_B     `EXTOP_LENGTH'd4                                         // immb
`define EXTOP_J     `EXTOP_LENGTH'd5                                          // immj
`define EXTOP_R     `EXTOP_LENGTH'd6                                          // immr

`define IMM_DEFAULT `DATA_WIDTH'd0                                          // immi default value

// alu source 
`define ALU_ASRC_LENGTH 1                                            // Length of signal ALUAsrc
`define ALU_ASRC_PC `ALU_ASRC_LENGTH'b1                                  // ALUAsrc PC
`define ALU_ASRC_RS1 `ALU_ASRC_LENGTH'b0                                 // ALUAsrc rs1

`define ALU_BSRC_LENGTH 1                                            // Length of signal ALUBsrc
`define ALU_BSRC_RS2 `ALU_BSRC_LENGTH'b0                                  // ALUBsrc rs2
`define ALU_BSRC_IMM `ALU_BSRC_LENGTH'b1                                  // ALUBsrc imm

// ALU control signals
`define ALU_CTRL_LENGTH   4                                         // Length of signal ALUctr
`define ALU_CTRL_DEFAULT  `ALU_CTRL_LENGTH'b0000                                  // ALUctr default value, do add
`define ALU_CTRL_ADD      `ALU_CTRL_LENGTH'b0000                                // ALU add
`define ALU_CTRL_SUB      `ALU_CTRL_LENGTH'b1000                                  // ALU sub
`define ALU_CTRL_SLL      `ALU_CTRL_LENGTH'b0001                                  // ALU shift left
`define ALU_CTRL_SLT     `ALU_CTRL_LENGTH'b0010                                 // ALU less than
`define ALU_CTRL_SLTU    `ALU_CTRL_LENGTH'b1010                                 // ALU unsinged less than 
`define ALU_CTRL_COPY_B     `ALU_CTRL_LENGTH'b0011                                  // ALU output B source
`define ALU_CTRL_XOR      `ALU_CTRL_LENGTH'b0100                                   // ALU xor
`define ALU_CTRL_SLR      `ALU_CTRL_LENGTH'b0101                                  // ALU shift logic right
`define ALU_CTRL_SAR      `ALU_CTRL_LENGTH'b1101                                  // ALU shift arithmetic right
`define ALU_CTRL_OR       `ALU_CTRL_LENGTH'b0110                                   // ALU or
`define ALU_CTRL_AND      `ALU_CTRL_LENGTH'b0111                                   // ALU and

// branch control signals
`define BRANCH_COND_LENGTH  3                                       // Length of signal BranchCond
`define BRANCH_COND_DEFAULT `BRANCH_COND_LENGTH'b010                           // BranchCond default value, not branch
`define BRANCH_COND_EQ      `BRANCH_COND_LENGTH'b000                           // BranchCond condition jump when equal
`define BRANCH_COND_NE   `BRANCH_COND_LENGTH'b001                           // BranchCond condition jump when not equal
`define BRANCH_COND_LT     `BRANCH_COND_LENGTH'b100                           // BranchCond condition jump when less than
`define BRANCH_COND_GE     `BRANCH_COND_LENGTH'b101                           // BranchCond condition jump when great than or equal
`define BRANCH_COND_LTU  `BRANCH_COND_LENGTH'b110                           // BranchCond condition jump when unsigned less than
`define BRANCH_COND_GEU   `BRANCH_COND_LENGTH'b111                           // BranchCond condition jump when unsigned great than or equal

// Memory control signals determined by func3
`define MEM_CTRL_LENGTH   3                                         // Length of signal Memctr
`define MEM_CTRL_LOAD_BYTE  `MEM_CTRL_LENGTH'b000                                   // Memctr load byte
`define MEM_CTRL_LOAD_HALFWORD `MEM_CTRL_LENGTH'b001                                // Memctr load halfword
`define MEM_CTRL_LOAD_WORD `MEM_CTRL_LENGTH'b010                                   // Memctr load word
`define MEM_CTRL_LOAD_BYTE_U `MEM_CTRL_LENGTH'b100                                // Memctr load byte unsigned
`define MEM_CTRL_LOAD_HALFWORD_U `MEM_CTRL_LENGTH'b101                             // Memctr load halfword unsigned
`define MEM_CTRL_STORE_BYTE `MEM_CTRL_LENGTH'b000                                  // Memctr store byte
`define MEM_CTRL_STORE_HALFWORD `MEM_CTRL_LENGTH'b001                             // Memctr store halfword
`define MEM_CTRL_STORE_WORD `MEM_CTRL_LENGTH'b010                                  // Memctr store word

// Register Write back control signals
`define REG_ADDR_WIDTH 5                                                // Register addr width

`define REG_WRITE_BACK_SEL_LENGTH 2                                       // Length of signal RegWriteSel
`define REG_WRITE_BACK_SEL_PC_4 `REG_WRITE_BACK_SEL_LENGTH'd0                   // RegWriteSel PC + 4
`define REG_WRITE_BACK_SEL_ALU `REG_WRITE_BACK_SEL_LENGTH'd1                      // RegWriteSel alu output
`define REG_WRITE_BACK_SEL_MEM  `REG_WRITE_BACK_SEL_LENGTH'd2                      // RegWriteSel memory output

// forwarding signals
`define FORWARDING_A_LENGTH 2                                            // Length of signal ForwardA
`define FORWARDING_A_ID_EX `FORWARDING_A_LENGTH'b00                            // alu source a is from register id
`define FORWARDING_A_EXE_MEM `FORWARDING_A_LENGTH'b10                           // alu source a is from last alu output
`define FORWARDING_A_MEM_WB `FORWARDING_A_LENGTH'b01                           // alu source a is from memory output or more older alu output

`define FORWARDING_B_LENGTH 2                                            // Length of signal ForwardB
`define FORWARDING_B_ID_EX `FORWARDING_B_LENGTH'b00                            // alu source b is from register id
`define FORWARDING_B_EXE_MEM `FORWARDING_B_LENGTH'b10                           // alu source b is from last alu output
`define FORWARDING_B_MEM_WB `FORWARDING_B_LENGTH'b01                           // alu source b is from memory output or more older alu output

// for debug
`define DIFFTEST 1
