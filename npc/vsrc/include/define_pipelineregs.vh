`include "define.vh"

/******************************************** pipeline stage bus width ********************************************/
`define IF_ID_BUS_WIDTH  (`PC_WIDTH + `INSTR_WIDTH + `PC_WIDTH )
`define ID_EXE_BUS_WIDTH (`PC_WIDTH + `DATA_WIDTH + `PC_WIDTH + 1 + `REG_WRITE_BACK_SEL_LENGTH + 1 + 1 + `ALU_CTRL_LENGTH + 1 + 1 + `BRANCH_COND_LENGTH + `MEM_CTRL_LENGTH + 1 + 1 + `DATA_WIDTH + 3*`REG_ADDR_WIDTH + 2*`DATA_WIDTH )
`define EXE_MEM_BUS_WIDTH (`PC_WIDTH + `DATA_WIDTH + `PC_WIDTH + 1 + `REG_WRITE_BACK_SEL_LENGTH + `MEM_CTRL_LENGTH + 1 + 1 + `REG_ADDR_WIDTH + `DATA_WIDTH + `DATA_WIDTH + 1 )
`define MEM_WB_BUS_WIDTH (`PC_WIDTH + `DATA_WIDTH + `PC_WIDTH + 1 + `REG_WRITE_BACK_SEL_LENGTH + `REG_ADDR_WIDTH + `DATA_WIDTH + `DATA_WIDTH + 1 )


/******************************************** pipeline registers ********************************************/
// // if_id state
// typedef struct {
//     logic [`PC_WIDTH-1:0] PC;
//     logic [`DATA_WIDTH-1:0] Instr;
//     logic [`PC_WIDTH-1:0] PC_4;
// } type_if_id_reg;

// // id_exe state
// typedef struct {
//     // expends from if stage
//     logic [`PC_WIDTH-1:0] PC;
//     logic [`DATA_WIDTH-1:0] Instr;
//     logic [`PC_WIDTH-1:0] PC_4;
//     // control signals from control unit
//     logic reg_wen;
//     logic [`REG_WRITE_BACK_SEL_LENGTH-1:0] reg_wb_sel;
//     logic aluasrc;
//     logic alubsrc;
//     logic [`ALU_CTRL_LENGTH-1:0] alu_op;
//     logic do_branch;
//     logic do_jump;
//     logic [`BRANCH_COND_LENGTH-1:0] branch_cond;
//     logic [`MEM_CTRL_LENGTH-1:0] mem_op;
//     logic mem_wen;
//     logic mem_ren;
//     // immediate value from imm generator
//     logic [`DATA_WIDTH-1:0] imm;
//     // decoder output for regfile
//     logic [`REG_ADDR_WIDTH-1:0] raddr1;
//     logic [`REG_ADDR_WIDTH-1:0] raddr2;
//     logic [`REG_ADDR_WIDTH-1:0] reg_waddr;
//     // register file output
//     logic [`DATA_WIDTH-1:0] rdata1;
//     logic [`DATA_WIDTH-1:0] rdata2;
// } type_id_exe_reg;

// // exe_mem state
// typedef struct {
//     // expends from id stage
//     logic [`PC_WIDTH-1:0] PC;
//     logic [`DATA_WIDTH-1:0] Instr;
//     logic [`PC_WIDTH-1:0] PC_4;
//     // control signals hold from id stage
//     logic reg_wen;
//     logic [`REG_WRITE_BACK_SEL_LENGTH-1:0] reg_wb_sel;
//     logic [`MEM_CTRL_LENGTH-1:0] mem_op;
//     logic mem_wen;
//     logic mem_ren;
//     // decoder output for regfile
//     logic [`REG_ADDR_WIDTH-1:0] reg_waddr;
//     // alu output
//     logic [`DATA_WIDTH-1:0] alu_out;
//     // rs2 for memory datain
//     logic [`DATA_WIDTH-1:0] rs2;
// } type_exe_mem_reg;

// // mem_wb state
// typedef struct {
//     // expends from exe stage
//     logic [`PC_WIDTH-1:0] PC;
//     logic [`DATA_WIDTH-1:0] Instr;
//     logic [`PC_WIDTH-1:0] PC_4;
//     // control signals hold from exe stage
//     logic reg_wen;
//     logic [`REG_WRITE_BACK_SEL_LENGTH-1:0] reg_wb_sel;
//     // decoder output for regfile
//     logic [`REG_ADDR_WIDTH-1:0] reg_waddr;
//     // alu output
//     logic [`DATA_WIDTH-1:0] alu_out;
//     // memory output
//     logic [`DATA_WIDTH-1:0] mem_out;
// } type_mem_wb_reg;

