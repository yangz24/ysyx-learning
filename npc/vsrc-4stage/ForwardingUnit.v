`include "define.v"

module ForwardingUnit (
    input wire [`ADDR_WIDTH-1:0] EXReg_Regrs1,
    input wire [`ADDR_WIDTH-1:0] EXReg_Regrs2,
    input wire [`ADDR_WIDTH-1:0] WBReg_Regrd,
    input wire WBReg_RegWr,
    output wire   ForwardingA,
    output wire   ForwardingB
);

assign ForwardingA = (WBReg_RegWr && WBReg_Regrd != 0 && WBReg_Regrd == EXReg_Regrs1) ? 1'b1 :  1'b0; // 1'b1 表示ALU的第一个源操作数来自数据存储器或者更早的EXE执行结果的前递, 0表示来自寄存器堆

assign ForwardingB = (WBReg_RegWr && WBReg_Regrd != 0 && WBReg_Regrd == EXReg_Regrs2) ? 1'b1 :  1'b0;


endmodule