`include "define.vh"
`include "define_pipelineregs.vh"

module EXE_MEM_REG (
    input wire clk,
    input wire rst,

    // expends from id stage
    input wire [`PC_WIDTH-1:0] PC,
    input wire [`DATA_WIDTH-1:0] Instr,
    input wire [`PC_WIDTH-1:0] PC_4,
    // control signals hold from id stage
    input wire reg_wen,
    input wire [`REG_WRITE_BACK_SEL_LENGTH-1:0] reg_wb_sel,
    input wire [`MEM_CTRL_LENGTH-1:0] mem_op,
    input wire mem_wen,
    input wire mem_ren,
    // decoder output for regfile
    input wire [`REG_ADDR_WIDTH-1:0] reg_waddr,
    // alu output
    input wire [`DATA_WIDTH-1:0] alu_out,

    // rs2 for memory datain
    input wire [`DATA_WIDTH-1:0] rs2,

    // bpu clear control, when set to 1, clear the IF/ID/EX pipeline
    input wire bpu_clear_ctrl,

    // exe_mem_reg pipeline registers
    output type_exe_mem_reg exe_mem_reg
);

    always @(posedge clk ) begin
        if (rst || bpu_clear_ctrl) begin
            exe_mem_reg.PC <= 0;
            exe_mem_reg.Instr <= 0;
            exe_mem_reg.PC_4 <= 0;
            exe_mem_reg.reg_wen <= 0;
            exe_mem_reg.reg_wb_sel <= 0;
            exe_mem_reg.mem_op <= 0;    
            exe_mem_reg.mem_wen <= 0;
            exe_mem_reg.mem_ren <= 0;
            exe_mem_reg.reg_waddr <= 0;
            exe_mem_reg.alu_out <= 0;
            exe_mem_reg.rs2 <= 0;
        end
        else begin
            exe_mem_reg.PC <= PC;
            exe_mem_reg.Instr <= Instr;
            exe_mem_reg.PC_4 <= PC_4;
            exe_mem_reg.reg_wen <= reg_wen;
            exe_mem_reg.reg_wb_sel <= reg_wb_sel;
            exe_mem_reg.mem_op <= mem_op;
            exe_mem_reg.mem_wen <= mem_wen;
            exe_mem_reg.mem_ren <= mem_ren;
            exe_mem_reg.reg_waddr <= reg_waddr;
            exe_mem_reg.alu_out <= alu_out;
            exe_mem_reg.rs2 <= rs2;
        end
    end

    
endmodule