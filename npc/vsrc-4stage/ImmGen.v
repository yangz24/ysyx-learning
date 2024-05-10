`include "define.v"

module ImmGen (
    input wire [`DATA_WIDTH-1:0] Instr,
    input wire [2:0] ExtOp,
    output reg [`DATA_WIDTH-1:0] Imm 
);

wire [`DATA_WIDTH-1:0] immI, immU, immS, immB, immJ;

assign immI = {{20{Instr[31]}}, Instr[31:20]};
assign immU = {Instr[31:12], 12'b0};
assign immS = {{20{Instr[31]}}, Instr[31:25], Instr[11:7]};
assign immB = {{20{Instr[31]}}, Instr[7], Instr[30:25], Instr[11:8], 1'b0};
assign immJ = {{12{Instr[31]}}, Instr[19:12], Instr[20], Instr[30:21], 1'b0};

always @(*) begin
    case (ExtOp)
        3'b000: Imm = immI;
        3'b001: Imm = immU;
        3'b010: Imm = immS;
        3'b011: Imm = immB;
        3'b100: Imm = immJ; 
        default: Imm = 32'b0;
    endcase
end
    
endmodule
