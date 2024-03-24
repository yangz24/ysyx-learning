module PreDecoder #(
    DATA_WIDTH = 32
) (
    input wire [DATA_WIDTH-1:0] Instr,
    output wire [6:0] op,
    output wire [4:0] rs1,
    output wire [4:0] rs2,
    output wire [4:0] rd,
    output wire [2:0] func3,
    output wire [6:0] func7
);

assign  op  = Instr[6:0];
assign  rs1 = Instr[19:15];
assign  rs2 = Instr[24:20];
assign  rd  = Instr[11:7];
assign  func3  = Instr[14:12];
assign  func7  = Instr[31:25];

import "DPI-C" function void npc_trap();
always @(*) begin
    case (Instr)
        32'b00000000000000000000000001110011: begin npc_trap(); end    // ebreak
        default:;
    endcase
end

endmodule
