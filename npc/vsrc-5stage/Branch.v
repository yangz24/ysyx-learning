`include "defines.v"

module Branch (
    input wire [`BRANCH_COND_LENGTH-1:0] branch_op,
    input wire [`DATA_WIDTH-1:0] rs1,
    input wire [`DATA_WIDTH-1:0] rs2,
    output wire branch_taken
    );

    assign branch_taken = (branch_op == `BRANCH_COND_EQ)? (rs1 == rs2) : 
                          (branch_op == `BRANCH_COND_NE)? (rs1!= rs2) : 
                          (branch_op == `BRANCH_COND_LT)? ($signed(rs1) < $signed(rs2)) : 
                          (branch_op == `BRANCH_COND_GE)? ($signed(rs1) >= $signed(rs2)) :
                          (branch_op == `BRANCH_COND_LTU)? (rs1 < rs2) :
                          (branch_op == `BRANCH_COND_GEU)? (rs1 >= rs2) : 1'b0;

    
endmodule