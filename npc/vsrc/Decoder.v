`include "define.vh"

module Decoder (
    input [`INSTR_WIDTH-1:0] Instr,
    output [`REG_ADDR_WIDTH-1:0] raddr1,
    output [`REG_ADDR_WIDTH-1:0] raddr2,
    output [`REG_ADDR_WIDTH-1:0] waddr,
    output wire [2:0] func3,
    output wire [6:0] func7,
    output [`OPCODE_LENGTH-1:0] opcode
);

assign  raddr1 = Instr[19:15];
assign  raddr2 = Instr[24:20];
assign  waddr  = Instr[11:7];
assign  func3  = Instr[14:12];
assign  func7  = Instr[31:25];
assign  opcode  = Instr[6:0];
    
endmodule
