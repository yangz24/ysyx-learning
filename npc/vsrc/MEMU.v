`include "define.vh"
`include "define_pipelineregs.vh"

module MEMU (
    input wire clk,
    input wire rst,

    // exe_mem_bus input
    input wire [`EXE_MEM_BUS_WIDTH-1:0] exe_mem_bus,

    // bpu flush pipeline register
    input wire bpu_clear_ctrl, 

    // alu_out forwarding 
    output wire [`DATA_WIDTH-1:0] exe_mem_reg_alu_out,

    // for forwarding detection
    output wire [`REG_ADDR_WIDTH-1:0] exe_mem_reg_waddr,
    output wire exe_mem_reg_wen,

    // mem_wb_bus output
    output wire [`MEM_WB_BUS_WIDTH-1:0] mem_wb_bus
);

/******************************************** exe_mem_reg pipeline register ********************************************/
reg [`EXE_MEM_BUS_WIDTH-1:0] exe_mem_reg;

/******************************************** internal use signals ********************************************/
wire [`MEM_CTRL_LENGTH-1:0] mem_op;
wire mem_wen;
wire mem_ren;
wire [`DATA_WIDTH-1:0] rs2;

/******************************************** mem_wb_bus signals ********************************************/
// expends from exe stage
wire [`PC_WIDTH-1:0] PC;
wire [`DATA_WIDTH-1:0] Instr;
wire [`PC_WIDTH-1:0] PC_4;
// control signals hold from exe stage
wire reg_wen;
wire [`REG_WRITE_BACK_SEL_LENGTH-1:0] reg_wb_sel;
// decoder output for regfile
wire [`REG_ADDR_WIDTH-1:0] reg_waddr;
// alu output
wire [`DATA_WIDTH-1:0] alu_out;
// memory output
wire [`DATA_WIDTH-1:0] mem_out;

// for debug
wire diffen;
wire branch_taken;

/******************************************** exe_mem_reg update ********************************************/
always @(posedge clk ) begin
    if (rst )begin //|| bpu_clear_ctrl) begin
        exe_mem_reg <= 0;
    end
    else begin
        exe_mem_reg <= exe_mem_bus;
    end
end

assign {
    PC,
    Instr,
    PC_4,
    reg_wen,
    reg_wb_sel,
    mem_op,
    mem_wen,
    mem_ren,
    reg_waddr,
    alu_out,
    rs2,
    diffen,
    branch_taken    
} = exe_mem_reg;

/******************************************** alu_out forwarding ********************************************/
assign exe_mem_reg_alu_out = alu_out;

/******************************************** for forwarding detection ********************************************/
assign exe_mem_reg_waddr = reg_waddr;
assign exe_mem_reg_wen = reg_wen;

/******************************************** Data Memory Control ********************************************/
DataMemCtrl u_DataMemCtrl(
    .clk                               (clk                       ),
    .rst                               (rst                       ),
    .addr                              (alu_out                   ),
    .mem_op                            (mem_op                    ),
    .mem_wen                           (mem_wen                   ),
    .mem_ren                           (mem_ren                   ),
    .data_in                           (rs2                       ),
    .data_out                          (mem_out                   ) 
);

/******************************************** mem_wb_bus output ********************************************/
assign mem_wb_bus = {
    PC,
    Instr,
    PC_4,
    reg_wen,
    reg_wb_sel,
    reg_waddr,
    alu_out,
    mem_out,
    diffen,
    branch_taken
};

endmodule