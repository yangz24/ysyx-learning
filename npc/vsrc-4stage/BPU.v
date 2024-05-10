`include "define.v" 

module BPU (
    input wire PCsrc,
    output wire BPUClearCtr
);
    
assign BPUClearCtr = PCsrc? 1 : 0;

endmodule