`include "define.vh"

`ifdef DIFFTEST

module Difftest (
    input  wire                         clk                        ,
    input  wire                         rst                        ,

    // diff signal from wb stage
    input  wire                         diffen                     ,
    input  wire        [`DATA_WIDTH-1:0]PC                         ,
    input  wire        [`DATA_WIDTH-1:0]Instr                      ,
    input  wire                         branch_taken               ,


    // branch PC
    input  wire        [`DATA_WIDTH-1:0]branch_PC                  ,

    // real difftest signals 
    output reg                           diff_enable                ,
    output reg         [`DATA_WIDTH-1:0]diff_PC                    ,
    output reg         [`DATA_WIDTH-1:0]diff_Instr                 ,
    output reg         [`DATA_WIDTH-1:0]nextPC                      
);

// real difftest branch_taken signal
reg diff_branch_taken;

/******************************************** difftest enable ********************************************/

always @(posedge clk ) begin
    if (rst) begin
        diff_enable <= 0;
    end
    else begin
        diff_enable <= diffen;
    end
end
/******************************************** difftest PC and Instr ********************************************/
always @(posedge clk ) begin
    if (rst) begin
        diff_PC <= 0;
        diff_Instr <= 0;
    end
    else  begin
        diff_PC <= PC;
        diff_Instr <= Instr;
    end
end

/******************************************** difftest nextPC **********/
always @(posedge clk ) begin
    if (rst) begin
        diff_branch_taken <= 0;
    end
    else  begin
        diff_branch_taken <= branch_taken;
    end
end

assign nextPC = diff_branch_taken? branch_PC : PC;

endmodule

`endif