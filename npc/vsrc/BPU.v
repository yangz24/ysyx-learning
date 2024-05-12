`include "define.vh" 

module BPU (
    input wire clk,
    input wire rst,

    // PC source signal control
    input wire branch_taken,

    // BPU clear control signal
    output reg bpu_clear_ctrl
);

// always @(posedge clk ) begin
//     if (rst) begin
//         bpu_clear_ctrl <= 0;
//     end
//     else if (branch_taken) begin
//         bpu_clear_ctrl <= 1;
//     end
//     else begin
//         bpu_clear_ctrl <= 0;
//     end
// end    

assign bpu_clear_ctrl = branch_taken;

endmodule