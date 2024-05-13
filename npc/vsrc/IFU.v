`include "define.vh"
`include "define_pipelineregs.vh"

module IFU (
    input wire clk,
    input wire rst,

    // branch taken, and target PC
    input wire branch_taken,
    input wire [`PC_WIDTH-1:0] branch_PC,

    // // enable PC change, when detected a hazard, do not change PC
    // input wire PC_enable,

    // hazard detected flag
    input wire hazard_detected,

    // bpu flush signal
    input wire bpu_clear_ctrl,

    // // handshake signals with last stage
    // input wire s_valid,
    // output wire s_ready,

    // handshake signals with next stage
    output reg m_valid,
    input wire m_ready,

    // real newest PC and instruction for pipeline stage IF/ID
    output wire [`IF_ID_BUS_WIDTH-1:0] if_id_bus
);

/******************************************** if_id_bus signals ********************************************/
wire [`PC_WIDTH-1:0] PC;
wire [`INSTR_WIDTH-1:0] Instr;
wire [`PC_WIDTH-1:0] PC_4;
// for debug
// wire diffen = 1'b1;


/******************************************** PC generation ********************************************/
PcGen u_PcGen(
    .clk                               (clk                       ),
    .rst                               (rst                       ),
    .branch_taken                      (branch_taken              ),
    .branch_PC                         (branch_PC                 ),
    .PC_enable                         (~hazard_detected          ),
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

/******************************************** hansdshake with next stage **********/
wire s_ready;
wire ready_go = 1'b1; // data is prepared, ready to go
reg pipe_is_valid; 

assign pipe_is_valid = ~rst && ~bpu_clear_ctrl;
assign s_ready = ~pipe_is_valid || (m_ready && ready_go);
assign m_valid = pipe_is_valid && ready_go;

// always @(posedge clk ) begin
//     if (rst) begin
//         pipe_is_valid <= 0;
//     end
//     else if (s_ready) begin
//         pipe_is_valid <= s_valid;
//     end
// end

assign if_id_bus = {
    PC,
    Instr,
    PC_4
    // diffen
};


    
endmodule