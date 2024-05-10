`include "define.vh"

module IFU (
    input wire clk,
    input wire rst,

    // branch taken, and target PC
    input wire branch_taken,
    input wire [`PC_WIDTH-1:0] BranchPC,

    // enable PC change, when detected a hazard, do not change PC
    input wire PC_enable,

    // real newest PC and instruction
    output wire [`PC_WIDTH-1:0] PC,
    output wire [`INSTR_WIDTH-1:0] Instr,
    output wire [`PC_WIDTH-1:0] PC_4
);

PcGen u_PcGen(
    .clk          (clk          ),
    .rst          (rst          ),
    .branch_taken (branch_taken ),
    .BranchPC     (BranchPC     ),
    .PC_enable    (PC_enable    ),
    .PC           (PC           ),
    .PC_4         (PC_4         )
);

InstrMemCtrl u_InstrMemCtrl(
    .clk    (clk    ),
    .rst    (rst    ),
    .RdAddr (PC     ),
    .Instr  (Instr  )
);




    
endmodule