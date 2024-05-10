`include "define.v"

module PcGen (
    input wire clk,
    input wire rst,
    // input wire PCwrite,
    input wire PCsrc, 
    input wire [`DATA_WIDTH-1:0] BranchPC,
    output reg [`DATA_WIDTH-1:0] PC
);

parameter RESET_VAL = 32'h80000000;

wire [`DATA_WIDTH-1:0] PCA;
wire [`DATA_WIDTH-1:0] NextPC;

assign PCA = PC + 4;
assign NextPC = PCsrc? BranchPC : PCA; // 1 跳转, 0 不跳转

always @(posedge clk ) begin
    if (rst) begin
        PC <= RESET_VAL;
    end
    else begin // if (PCwrite == 1'b1) begin
        PC <= NextPC;
    end
end
    
endmodule
