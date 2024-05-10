`include "define.vh"
`include "define_pipelineregs.vh"

module MEM_WB_REG (
    input wire clk,
    input wire rst,

    // expends from exe stage
    input wire [`PC_WIDTH-1:0] PC,
    input wire [`DATA_WIDTH-1:0] Instr,
    input wire [`PC_WIDTH-1:0] PC_4,
    // control signals hold from exe stage
    input wire reg_wen,
    input wire [`REG_WRITE_BACK_SEL_LENGTH-1:0] reg_wb_sel,
    // decoder output for regfile
    input wire [`REG_ADDR_WIDTH-1:0] reg_waddr,
    // alu output
    input wire [`DATA_WIDTH-1:0] alu_out,
    // memory output
    input wire [`DATA_WIDTH-1:0] mem_out,

    // mem_wb_reg pipeline registers
    output type_mem_wb_reg mem_wb_reg
);

always @(posedge clk ) begin
    if (rst) begin
        mem_wb_reg.PC <= 0;
        mem_wb_reg.Instr <= 0;
        mem_wb_reg.PC_4 <= 0;
        mem_wb_reg.reg_wen <= 0;
        mem_wb_reg.reg_wb_sel <= 0;
        mem_wb_reg.reg_waddr <= 0;
        mem_wb_reg.alu_out <= 0;
        mem_wb_reg.mem_out <= 0;
    end
    else begin
        mem_wb_reg.PC <= PC;
        mem_wb_reg.Instr <= Instr;
        mem_wb_reg.PC_4 <= PC_4;
        mem_wb_reg.reg_wen <= reg_wen;
        mem_wb_reg.reg_wb_sel <= reg_wb_sel;
        mem_wb_reg.reg_waddr <= reg_waddr;
        mem_wb_reg.alu_out <= alu_out;
        mem_wb_reg.mem_out <= mem_out;
    end
end
    
endmodule