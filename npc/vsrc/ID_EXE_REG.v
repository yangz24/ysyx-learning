`include "define.vh"
`include "define_pipelineregs.vh"

module ID_EXE_REG (
    input wire clk,
    input wire rst,
    // expends from if stage
    input wire [`PC_WIDTH-1:0] PC,
    input wire [`DATA_WIDTH-1:0] Instr,
    input wire [`PC_WIDTH-1:0] PC_4,
    // control signals from control unit
    input wire reg_wen,
    input wire [`REG_WRITE_BACK_SEL_LENGTH-1:0] reg_wb_sel,
    input wire aluasrc,
    input wire alubsrc,
    input wire [`ALU_CTRL_LENGTH-1:0] alu_op,
    input wire do_branch,
    input wire do_jump,
    input wire [`BRANCH_COND_LENGTH-1:0] branch_cond,
    input wire [`MEM_CTRL_LENGTH-1:0] mem_op,
    input wire mem_wen,
    input wire mem_ren,
    // immediate value from imm generator
    input wire [`DATA_WIDTH-1:0] imm,
    // decoder output for regfile
    input wire [`REG_ADDR_WIDTH-1:0] raddr1,
    input wire [`REG_ADDR_WIDTH-1:0] raddr2,
    input wire [`REG_ADDR_WIDTH-1:0] reg_waddr,
    // register file output
    input wire [`DATA_WIDTH-1:0] rdata1,
    input wire [`DATA_WIDTH-1:0] rdata2,

    // clear pipeline registers 
    input wire hazard_clear_ctr,

    // bpu clear control, when set to 1, clear the IF/ID/EX pipeline
    input wire bpu_clear_ctrl,

    // id_exe_reg pipeline registers
    output type_id_exe_reg id_exe_reg
);

always @(posedge clk ) begin
    if (rst || hazard_clear_ctr || bpu_clear_ctrl) begin
        id_exe_reg.PC <= 0;
        id_exe_reg.Instr <= 0;
        id_exe_reg.PC_4 <= 0;
        id_exe_reg.reg_wen <= 0;
        id_exe_reg.reg_wb_sel <= 0;
        id_exe_reg.aluasrc <= 0;
        id_exe_reg.alubsrc <= 0;
        id_exe_reg.alu_op <= 0;
        id_exe_reg.do_branch <= 0;
        id_exe_reg.do_jump <= 0;
        id_exe_reg.branch_cond <= 0;
        id_exe_reg.mem_op <= 0;
        id_exe_reg.mem_wen <= 0;
        id_exe_reg.mem_ren <= 0;
        id_exe_reg.imm <= 0;
        id_exe_reg.raddr1 <= 0;
        id_exe_reg.raddr2 <= 0;
        id_exe_reg.reg_waddr <= 0;
        id_exe_reg.rdata1 <= 0;
        id_exe_reg.rdata2 <= 0;
    end
    else begin
        id_exe_reg.PC <= PC;
        id_exe_reg.Instr <= Instr;
        id_exe_reg.PC_4 <= PC_4;
        id_exe_reg.reg_wen <= reg_wen;
        id_exe_reg.reg_wb_sel <= reg_wb_sel;
        id_exe_reg.aluasrc <= aluasrc;
        id_exe_reg.alubsrc <= alubsrc;
        id_exe_reg.alu_op <= alu_op;
        id_exe_reg.do_branch <= do_branch;
        id_exe_reg.do_jump <= do_jump;
        id_exe_reg.branch_cond <= branch_cond;
        id_exe_reg.mem_op <= mem_op;
        id_exe_reg.mem_wen <= mem_wen;
        id_exe_reg.mem_ren <= mem_ren;
        id_exe_reg.imm <= imm;
        id_exe_reg.raddr1 <= raddr1;
        id_exe_reg.raddr2 <= raddr2;
        id_exe_reg.reg_waddr <= reg_waddr;
        id_exe_reg.rdata1 <= rdata1;
        id_exe_reg.rdata2 <= rdata2;
    end
end

endmodule