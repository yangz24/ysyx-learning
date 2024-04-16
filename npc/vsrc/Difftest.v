`include "define.v"

`ifdef DIFFTEST

module Difftest (
    input  wire                         wb_diffen                  ,
    input  wire        [`DATA_WIDTH-1:0]PC                         ,
    input  wire        [`DATA_WIDTH-1:0]Instr                      ,
    input  wire        [`DATA_WIDTH-1:0]IDReg_PC                   ,
    input  wire        [`DATA_WIDTH-1:0]WBReg_PC                   ,
    input  wire                         HoldPCsrc                  ,
    output reg                          diffen                     ,
    output reg         [`DATA_WIDTH-1:0]diffPC                     ,
    output reg         [`DATA_WIDTH-1:0]diffInstr                  ,
    output reg         [`DATA_WIDTH-1:0]nextPC                      
);

assign diffen = wb_diffen;
assign diffPC = wb_diffen? PC : 0;
assign diffInstr = wb_diffen? Instr : 0;
assign nextPC = HoldPCsrc? IDReg_PC : WBReg_PC;

endmodule

`endif