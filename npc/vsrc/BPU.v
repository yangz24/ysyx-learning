`include "define.vh" 

module BPU (
    // PC source signal control
    input wire branch_taken,

    // BPU clear control signal
    output wire bpu_clear_ctr
);
    
assign bpu_clear_ctr = branch_taken? 1 : 0;

endmodule