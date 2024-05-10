`include "define.vh"

module ALU (input [`DATA_WIDTH-1:0]A,            // 操作数1
            input [`DATA_WIDTH-1:0]B,            // 操作数2
            input [3:0] alu_op,                 // ALU 控制信号，用于选择ALU的具体操作
            output reg Zero,                     // 零标志位，如果结果为零则置1
            output reg Less,                     // 小于标志
            output reg [`DATA_WIDTH-1:0]alu_out); // ALU的计算结果
    
    wire                   [`DATA_WIDTH-1:0]add                        ;
    wire                   [`DATA_WIDTH-1:0]sub                        ;
    wire                   [`DATA_WIDTH-1:0]shiftleft                  ;
    wire                                    less_sign                  ;
    wire                                    less_unsign                ;
    wire                   [`DATA_WIDTH-1:0]alu_xor                    ;
    wire                   [`DATA_WIDTH-1:0]shift_right_l              ;
    wire                   [`DATA_WIDTH-1:0]shift_right_a              ;
    wire                   [`DATA_WIDTH-1:0]alu_or                     ;
    wire                   [`DATA_WIDTH-1:0]alu_and                    ;
    
    assign add           = A + B;
    assign sub           = A - B;
    assign shiftleft     = A << B[4:0];
    assign less_sign     = ($signed(A) < $signed(B))? 1'b1 : 1'b0;
    assign less_unsign   = (A < B)? 1'b1 : 1'b0;
    assign alu_xor       = A ^ B;
    assign shift_right_l = A >> B[4:0];
    assign shift_right_a = $signed(A) >>> B[4:0];
    assign alu_or        = A | B;
    assign alu_and       = A & B;
    
    assign Less = ((alu_op == `ALU_CTRL_SLT) && less_sign) | ((alu_op == `ALU_CTRL_SLTU) && less_unsign);
    
    assign Zero = (A == B)? 1 : 0;
    
    always @(*) begin
        casez (alu_op)
            `ALU_CTRL_ADD: alu_out = add;
            `ALU_CTRL_SUB: alu_out = sub;
            `ALU_CTRL_SLL: alu_out = shiftleft;
            `ALU_CTRL_SLT: alu_out = {`DATA_WIDTH_1'b0, less_sign};
            `ALU_CTRL_SLTU: alu_out = {31'b0, less_unsign};
            `ALU_CTRL_COPY_B: alu_out = B;
            `ALU_CTRL_XOR: alu_out = alu_xor;
            `ALU_CTRL_AND: alu_out = alu_and;
            `ALU_CTRL_OR: alu_out = alu_or;
            `ALU_CTRL_SLR: alu_out = shift_right_l;
            `ALU_CTRL_SAR: alu_out = shift_right_a;
            default: alu_out = 0;
        endcase
    end


endmodule
    
    
