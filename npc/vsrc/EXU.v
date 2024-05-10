`include "define.vh"
`include "define_pipelineregs.vh"

module EXU (
    // id_exe_reg input
    input type_id_exe_reg id_exe_reg,

    // forwarding selection
    input [`FORWARDING_A_LENGTH-1:0] forwardingA,
    input [`FORWARDING_B_LENGTH-1:0] forwardingB,

    // forwarding data
    input [`DATA_WIDTH-1:0] exe_mem_reg_alu_out,
    input [`DATA_WIDTH-1:0] mem_wb_reg_wdata,

    // branch judgement output
    output wire branch_taken,

    // hold on pipeline signals
    // expends from id stage
    output wire [`PC_WIDTH-1:0] PC,
    output wire [`DATA_WIDTH-1:0] Instr,
    output wire [`PC_WIDTH-1:0] PC_4,
    // control signals hold from id stage
    output wire reg_wen,
    output wire [`REG_WRITE_BACK_SEL_LENGTH-1:0] reg_wb_sel,
    output wire [`MEM_CTRL_LENGTH-1:0] mem_op,
    output wire mem_wen,
    output wire mem_ren,
    // decoder output for regfile
    output wire [`REG_ADDR_WIDTH-1:0] reg_waddr,

    // alu output for pipeline reg
    output wire [`DATA_WIDTH-1:0] alu_out,

    // rs2 for pipeline reg
    output wire [`DATA_WIDTH-1:0] rs2
);

// real rs1 and rs2
wire [`DATA_WIDTH-1:0] rs1;

// alu source
wire [`DATA_WIDTH-1:0] A;
wire [`DATA_WIDTH-1:0] B;

// conditional branch judgement output
wire cond_branch_taken;

// reserved for future use
wire Zero;
wire Less;

/******************************************** forwarding ********************************************/

assign rs1 = (forwardingA == `FORWARDING_A_EXE_MEM)? exe_mem_reg_alu_out : // rs1 is from last alu output
             (forwardingA == `FORWARDING_A_MEM_WB)? mem_wb_reg_wdata : // rs1 is from mem_wb_reg
             id_exe_reg.rdata1; // rs1 is from id_exe_reg

assign rs2 = (forwardingB == `FORWARDING_B_EXE_MEM)? exe_mem_reg_alu_out : // rs1 is from last alu output
             (forwardingB == `FORWARDING_B_MEM_WB)? mem_wb_reg_wdata : // rs1 is from mem_wb_reg
             id_exe_reg.rdata2; // rs1 is from id_exe_reg

/******************************************** alu module ********************************************/

assign A = (id_exe_reg.aluasrc == `ALU_ASRC_RS1)? rs1 : id_exe_reg.PC;
assign B = (id_exe_reg.alubsrc == `ALU_BSRC_RS2)? rs2 : id_exe_reg.imm;

ALU u_ALU(
    .A                                 (A                         ),
    .B                                 (B                         ),
    .alu_op                            (id_exe_reg.alu_op         ),
    .Zero                              (Zero                      ),
    .Less                              (Less                      ),
    .alu_out                           (alu_out                   ) 
);

/******************************************** branch judgement ********************************************/

Branch u_Branch(
    .branch_op                         (id_exe_reg.branch_cond      ),
    .rs1                               (rs1                       ),
    .rs2                               (rs2                       ),
    .cond_branch_taken                 (cond_branch_taken         ) 
);

assign branch_taken = (id_exe_reg.do_branch & cond_branch_taken) | id_exe_reg.do_jump;

/******************************************** hold on pipeline signals ********************************************/
assign PC = id_exe_reg.PC;
assign Instr = id_exe_reg.Instr;
assign PC_4 = id_exe_reg.PC_4;
assign reg_wen = id_exe_reg.reg_wen;
assign reg_wb_sel = id_exe_reg.reg_wb_sel;
assign mem_op = id_exe_reg.mem_op;
assign mem_wen = id_exe_reg.mem_wen;
assign mem_ren = id_exe_reg.mem_ren;
assign reg_waddr = id_exe_reg.reg_waddr;

endmodule