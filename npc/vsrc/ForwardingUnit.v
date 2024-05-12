`include "define.vh"

module ForwardingUnit (
    // read regfile addr
    input wire [`REG_ADDR_WIDTH-1:0] id_exe_reg_raddr1,
    input wire [`REG_ADDR_WIDTH-1:0] id_exe_reg_raddr2,

    // write regfile addr
    input wire [`REG_ADDR_WIDTH-1:0] exe_mem_reg_waddr,
    input wire [`REG_ADDR_WIDTH-1:0] mem_wb_reg_waddr,

    // write regfile enable
    input wire exe_mem_reg_wen,
    input wire mem_wb_reg_wen,

    // forwarding signals
    output wire [`FORWARDING_A_LENGTH-1:0]  forwardingA,
    output wire [`FORWARDING_B_LENGTH-1:0]  forwardingB
);

assign forwardingA = (exe_mem_reg_wen &&  
                      exe_mem_reg_waddr != 0 && 
                      exe_mem_reg_waddr == id_exe_reg_raddr1) ? `FORWARDING_A_EXE_MEM : 
                     (mem_wb_reg_wen && 
                     mem_wb_reg_waddr != 0 && 
                     mem_wb_reg_waddr == id_exe_reg_raddr1) ? `FORWARDING_A_MEM_WB : 
                     `FORWARDING_A_ID_EX;

assign forwardingB = (exe_mem_reg_wen &&  
                      exe_mem_reg_waddr != 0 && 
                      exe_mem_reg_waddr == id_exe_reg_raddr2) ? `FORWARDING_B_EXE_MEM : 
                     (mem_wb_reg_wen && 
                     mem_wb_reg_waddr != 0 && 
                     mem_wb_reg_waddr == id_exe_reg_raddr2) ? `FORWARDING_B_MEM_WB : 
                     `FORWARDING_B_ID_EX;


endmodule