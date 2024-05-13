`include "define.vh"

module HazardDetectionUnit (
    input wire id_exe_reg_mem_ren,
    input wire [`REG_ADDR_WIDTH-1:0] id_exe_reg_waddr,
    input wire [`REG_ADDR_WIDTH-1:0] if_id_reg_raddr1,
    input wire [`REG_ADDR_WIDTH-1:0] if_id_reg_raddr2,

    // hazard detected flag
    output wire hazard_detected

    // // enable PC change
    // output wire PC_enable,

    // // enable if_id pipeline register change
    // output wire if_id_reg_enable,

    // // clear control signal
    // output wire hazard_clear_ctrl
);

assign hazard_detected = (id_exe_reg_mem_ren && ((id_exe_reg_waddr == if_id_reg_raddr1) || (id_exe_reg_waddr == if_id_reg_raddr2)))? 1 : 0; 

// assign PC_enable = (id_exe_reg_mem_ren && ((id_exe_reg_waddr == if_id_reg_raddr1) || (id_exe_reg_waddr == if_id_reg_raddr2)))? 0 : 1; 
// assign if_id_reg_enable = (id_exe_reg_mem_ren && ((id_exe_reg_waddr == if_id_reg_raddr1) || (id_exe_reg_waddr == if_id_reg_raddr2)))? 0 : 1; 
// assign hazard_clear_ctrl = (id_exe_reg_mem_ren && ((id_exe_reg_waddr == if_id_reg_raddr1) || (id_exe_reg_waddr == if_id_reg_raddr2)))? 1 : 0; 

endmodule