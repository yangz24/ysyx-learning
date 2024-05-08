`include "define.vh"

module PcGen (
    input wire clk,
    input wire rst,
    // input wire PCwrite,
    input wire branch_taken, 
    input wire [`DATA_WIDTH-1:0] BranchPC,
    output reg [`DATA_WIDTH-1:0] PC
);

/******************************************** temp variable ********************************************/
wire [`DATA_WIDTH-1:0] PCA;
wire [`DATA_WIDTH-1:0] NextPC;

assign PCA = PC + `PC_add_4;
assign NextPC = branch_taken? BranchPC : PCA; // branch_taken for jump

// PC generate
always @(posedge clk ) begin
    if (rst) begin
        PC <= `PCStart;
    end
    else begin 
        PC <= NextPC;
    end
end
    
endmodule
