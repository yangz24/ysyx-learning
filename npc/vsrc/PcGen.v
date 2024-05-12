`include "define.vh"

module PcGen (
    input wire clk,
    input wire rst,

    // branch_taken for jump
    input wire branch_taken, 

    // branch_PC for jump
    input wire [`PC_WIDTH-1:0] branch_PC,

    // enable PC change
    input wire PC_enable,

    // PC adn PC + 4
    output reg [`PC_WIDTH-1:0] PC,
    output wire [`PC_WIDTH-1:0] PC_4
);

/******************************************** next PC ********************************************/
wire [`PC_WIDTH-1:0] NextPC;

// PC_4 generate
    assign PC_4 = PC + `PC_add_4;

assign NextPC = branch_taken? branch_PC : PC_4; // branch_taken for jump

// PC generate
always @(posedge clk ) begin
    if (rst) begin
        PC <= `PCStart;
    end
    else if (PC_enable) begin 
        PC <= NextPC;
    end
end


    
endmodule
