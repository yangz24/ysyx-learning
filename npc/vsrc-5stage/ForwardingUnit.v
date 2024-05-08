`include "define.v"

module ForwardingUnit (
    // read regfile addr
    input wire [`ADDR_WIDTH-1:0] id_ex_reg_rs1,
    input wire [`ADDR_WIDTH-1:0] id_ex_reg_rs2,

    // write regfile addr
    input wire [`ADDR_WIDTH-1:0] ex_mem_reg_waddr,
    input wire [`ADDR_WIDTH-1:0] mem_wb_reg_waddr,

    // write regfile enable
    input wire ex_mem_reg_wen,
    input wire mem_wb_reg_wen,

    // forwarding signals
    output wire [1:0]  forwardingA,
    output wire [1:0]  forwardingB
);

assign forwardingA = (mem_wb_reg_wen && mem_wb_reg_waddr != 0 && mem_wb_reg_waddr == id_ex_reg_rs1) ? 1'b1 :  1'b0; // 1'b1 表示ALU的第一个源操作数来自数据存储器或者更早的EXE执行结果的前递, 0表示来自寄存器堆

assign forwardingB = (mem_wb_reg_wen && mem_wb_reg_waddr != 0 && mem_wb_reg_waddr == id_ex_reg_rs2) ? 1'b1 :  1'b0;


endmodule