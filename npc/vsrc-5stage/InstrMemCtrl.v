`include "define.vh"

module InstrMemCtrl (
    input wire clk,
    input wire rst,
    input wire [`DATA_WIDTH-1:0] RdAddr,
    output reg [`DATA_WIDTH-1:0] Instr
);


import "DPI-C" function int mem_read(input int Addr, input int isInstr);

always @(*) begin
    if (rst) begin
        Instr = 0;
    end
    else begin
        // $display("RdAddr = %x\n", RdAddr);
        Instr = mem_read(RdAddr, 1);
    end
end
    
endmodule