`include "define.vh"

module HazardDetectionUnit (
    input wire id_exe_reg_mem_ren,
    input wire [`REG_ADDR_WIDTH-1:0] id_exe_reg_waddr,
    input wire [`REG_ADDR_WIDTH-1:0] if_id_reg_rs1,
    input wire [`REG_ADDR_WIDTH-1:0] if_id_reg_rs2,

    // enable PC change
    output reg PC_enable,

    // enable if_id pipeline register change
    output reg if_id_reg_enable,

    // clear control signal
    output reg hazard_clear_ctr
);

assign PC_enable = (id_exe_reg_mem_ren && ((id_exe_reg_waddr == if_id_reg_rs1) || (id_exe_reg_waddr == if_id_reg_rs2)))? 0 : 1; 
assign if_id_reg_enable = (id_exe_reg_mem_ren && ((id_exe_reg_waddr == if_id_reg_rs1) || (id_exe_reg_waddr == if_id_reg_rs2)))? 0 : 1; 
assign hazard_clear_ctr = (id_exe_reg_mem_ren && ((id_exe_reg_waddr == if_id_reg_rs1) || (id_exe_reg_waddr == if_id_reg_rs2)))? 1 : 0; 

endmodule