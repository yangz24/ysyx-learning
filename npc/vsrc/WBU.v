`include "define.vh"
`include "define_pipelineregs.vh"

module WBU (
    input wire clk,
    input wire rst,
    // mem_wb_bus input
    input wire [`MEM_WB_BUS_WIDTH-1:0] mem_wb_bus,

    // for forwarding detection
    output wire [`REG_ADDR_WIDTH-1:0] mem_wb_reg_waddr,
    output wire mem_wb_reg_wen,

    // wb reg write enable
    output wire wb_reg_wen,

    // wb reg write address
    output wire [`REG_ADDR_WIDTH-1:0] wb_reg_waddr,

    // wb reg write data
    output wire [`DATA_WIDTH-1:0] wb_reg_wdata,

    // for debug
    output wire [`PC_WIDTH-1:0] PC,
    output wire [`INSTR_WIDTH-1:0] Instr,
    output wire diffen,
    output wire wb_branch_taken 
);

/******************************************** mem_wb_reg ********************************************/
reg [`MEM_WB_BUS_WIDTH-1:0] mem_wb_reg;

/******************************************** internal use signals ********************************************/
wire [`PC_WIDTH-1:0] PC_4;
wire reg_wen;
wire [`REG_WRITE_BACK_SEL_LENGTH-1:0] reg_wb_sel;
wire [`REG_ADDR_WIDTH-1:0] reg_waddr;
wire [`DATA_WIDTH-1:0] alu_out;
wire [`DATA_WIDTH-1:0] mem_out;


/******************************************** mem_wb_reg update ********************************************/
always @(posedge clk) begin
    if (rst) begin
        mem_wb_reg <= 0;
    end
    else begin
        mem_wb_reg <= mem_wb_bus;
    end
end

assign {
    PC,
    Instr,
    PC_4,
    reg_wen,
    reg_wb_sel,
    reg_waddr,
    alu_out,
    mem_out,
    diffen,
    wb_branch_taken
} = mem_wb_reg;

/******************************************** forwarding detection **********/
assign mem_wb_reg_waddr = reg_waddr;
assign mem_wb_reg_wen = reg_wen;

/******************************************** write back signals ********************************************/
assign wb_reg_wen = reg_wen;
assign wb_reg_waddr = reg_waddr;
assign wb_reg_wdata = (reg_wb_sel == `REG_WRITE_BACK_SEL_PC_4) ? PC_4 :
               (reg_wb_sel == `REG_WRITE_BACK_SEL_ALU) ? alu_out :
               mem_out;


/******************************************** ebreak instruction ********************************************/
import "DPI-C" function void npc_trap();
always @(posedge clk) begin
    case (Instr)
        32'b00000000000100000000000001110011: begin npc_trap(); end    // ebreak
        default:;
    endcase
end

endmodule