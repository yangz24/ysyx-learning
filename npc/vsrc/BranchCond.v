`include "define.v"

module BranchCond (
    input wire [2:0] Branch,
    input wire Less,
    input wire Zero,
    output reg PCAsrc,
    output reg PCBsrc,
    output reg PCsrc
);

always @(*) begin
    casez ({Branch, Zero, Less})
        5'b000zz: begin PCAsrc = 1'b0; PCBsrc = 1'b0; PCsrc = 0;   end   // PC + 4
        5'b001zz: begin PCAsrc = 1'b1; PCBsrc = 1'b0; PCsrc = 1;   end   // PC + imm
        5'b010zz: begin PCAsrc = 1'b1; PCBsrc = 1'b1; PCsrc = 1;   end   // rs1 + imm
        5'b1000z: begin PCAsrc = 1'b0; PCBsrc = 1'b0; PCsrc = 0;   end   // PC + 4
        5'b1001z: begin PCAsrc = 1'b1; PCBsrc = 1'b0; PCsrc = 1;   end   // PC + imm
        5'b1010z: begin PCAsrc = 1'b1; PCBsrc = 1'b0; PCsrc = 1;   end   // PC + imm
        5'b1011z: begin PCAsrc = 1'b0; PCBsrc = 1'b0; PCsrc = 0;   end   // PC + 4
        5'b110z0: begin PCAsrc = 1'b0; PCBsrc = 1'b0; PCsrc = 0;   end   // PC + 4
        5'b110z1: begin PCAsrc = 1'b1; PCBsrc = 1'b0; PCsrc = 1;   end   // PC + imm
        5'b111z0: begin PCAsrc = 1'b1; PCBsrc = 1'b0; PCsrc = 1;   end   // PC + imm
        5'b111z1: begin PCAsrc = 1'b0; PCBsrc = 1'b0; PCsrc = 0;   end   // PC + 4
        default:  begin PCAsrc = 1'b0; PCBsrc = 1'b0; PCsrc = 0;   end   // PC + 4
    endcase
end

endmodule

