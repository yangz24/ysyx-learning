`include "define.vh"
`include "define_pipelineregs.vh"

module WBU (
    // mem_wb_reg pipeline register
    input type_mem_wb_reg mem_wb_reg,

    // wb reg write enable
    output wire reg_wen,

    // wb reg write address
    output wire [`REG_ADDR_WIDTH-1:0] reg_waddr,

    // wb reg write data
    output wire [`DATA_WIDTH-1:0] reg_wdata
);

assign reg_wen = mem_wb_reg.reg_wen;
assign reg_waddr = mem_wb_reg.reg_waddr;
assign reg_wdata = (mem_wb_reg.reg_wb_sel == `REG_WRITE_BACK_SEL_PC_4) ? mem_wb_reg.PC_4 :
               (mem_wb_reg.reg_wb_sel == `REG_WRITE_BACK_SEL_ALU) ? mem_wb_reg.alu_out :
               mem_wb_reg.mem_out;
    
endmodule