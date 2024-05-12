`include "define.vh"
`include "define_pipelineregs.vh"

module IFU (
    input wire clk,
    input wire rst,

    // branch taken, and target PC
    input wire branch_taken,
    input wire [`PC_WIDTH-1:0] branch_PC,

    // enable PC change, when detected a hazard, do not change PC
    input wire PC_enable,

    // real newest PC and instruction for pipeline stage IF/ID
    output wire [`IF_ID_BUS_WIDTH-1:0] if_id_bus
);

/******************************************** if_id_bus signals ********************************************/
wire [`PC_WIDTH-1:0] PC;
wire [`INSTR_WIDTH-1:0] Instr;
wire [`PC_WIDTH-1:0] PC_4;
// for debug
wire diffen = 1'b1;


/******************************************** PC generation ********************************************/
PcGen u_PcGen(
    .clk                               (clk                       ),
    .rst                               (rst                       ),
    .branch_taken                      (branch_taken              ),
    .branch_PC                         (branch_PC                 ),
    .PC_enable                         (PC_enable                 ),
    .PC                                (PC                        ),
    .PC_4                              (PC_4                      ) 
);

/******************************************** Instruction memory controller **********/
InstrMemCtrl u_InstrMemCtrl(
    .clk    (clk    ),
    .rst    (rst    ),
    .RdAddr (PC     ),
    .Instr  (Instr  )
);

/******************************************** if_id_bus generation **********/
assign if_id_bus = {
    PC,
    Instr,
    PC_4,
    diffen
};


    
endmodule