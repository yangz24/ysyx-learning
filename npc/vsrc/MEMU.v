`include "define.vh"
`include "define_pipelineregs.vh"

module MEMU (
    input wire clk,
    input wire rst,

    // exe_mem_reg pipeline register input
    input type_exe_mem_reg exe_mem_reg,

    // hold on pipeline signals
    // expends from exe stage
    output wire  [`PC_WIDTH-1:0] PC,
    output wire  [`DATA_WIDTH-1:0] Instr,
    output wire  [`PC_WIDTH-1:0] PC_4,
    // control signals hold from exe stage
    output wire  reg_wen,
    output wire  [`REG_WRITE_BACK_SEL_LENGTH-1:0] reg_wb_sel,
    // decoder output for regfile
    output wire [`REG_ADDR_WIDTH-1:0] reg_waddr,
    // alu output
    output wire  [`DATA_WIDTH-1:0] alu_out,

    // Data memory output for pipeline register
    output wire [`DATA_WIDTH-1:0] mem_out
);

/******************************************** Data Memory Control ********************************************/
DataMemCtrl u_DataMemCtrl(
    .clk                               (clk                       ),
    .rst                               (rst                       ),
    .addr                              (exe_mem_reg.alu_out       ),
    .mem_op                            (exe_mem_reg.mem_op        ),
    .mem_wen                           (exe_mem_reg.mem_wen       ),
    .mem_ren                           (exe_mem_reg.mem_ren       ),
    .data_in                           (exe_mem_reg.rs2           ),
    .data_out                          (mem_out                   ) 
);

/******************************************** hold on pipeline signals ********************************************/
assign PC = exe_mem_reg.PC;
assign Instr = exe_mem_reg.Instr;
assign PC_4 = exe_mem_reg.PC_4;
assign reg_wen = exe_mem_reg.reg_wen;
assign reg_wb_sel = exe_mem_reg.reg_wb_sel;
assign reg_waddr = exe_mem_reg.reg_waddr;
assign alu_out = exe_mem_reg.alu_out;

endmodule