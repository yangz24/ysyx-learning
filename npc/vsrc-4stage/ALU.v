`include "define.v"

module ALU (
    input [`DATA_WIDTH-1:0] A, // 操作数1
    input [`DATA_WIDTH-1:0] B, // 操作数2
    input [3:0] ALUctr, // ALU 控制信号，用于选择ALU的具体操作
    output reg Zero, // 零标志位，如果结果为零则置1
    output reg Less, // 小于标志
    output reg [`DATA_WIDTH-1:0] ALUout // ALU的计算结果
);

wire [`DATA_WIDTH-1:0] add;
wire [`DATA_WIDTH-1:0] sub;
wire [`DATA_WIDTH-1:0] shiftleft;
wire less_sign;
wire less_unsign;
wire [`DATA_WIDTH-1:0] alu_xor;
wire [`DATA_WIDTH-1:0] shift_right_l;
wire [`DATA_WIDTH-1:0] shift_right_a;
wire [`DATA_WIDTH-1:0] alu_or;
wire [`DATA_WIDTH-1:0] alu_and;

assign add = A + B;
assign sub = A - B;
assign shiftleft = A << B[4:0];
assign less_sign = ($signed(A) < $signed(B))? 1'b1 : 1'b0;
assign less_unsign = (A < B)? 1'b1 : 1'b0;
assign alu_xor = A ^ B;
assign shift_right_l = A >> B[4:0];
assign shift_right_a = $signed(A) >>> B[4:0];
assign alu_or = A | B;
assign alu_and = A & B;

assign Less = ((ALUctr == 4'b0010) && less_sign) | ((ALUctr == 4'b1010) && less_unsign);

assign Zero = (A == B)? 1 : 0;

always @(*) begin
    casez (ALUctr)
        4'b0000: ALUout = add;
        4'b1000: ALUout = sub;
        4'bz001: ALUout = shiftleft;
        4'b0010: ALUout = {31'b0, less_sign};
        4'b1010: ALUout = {31'b0, less_unsign};
        4'bz011: ALUout = B;
        4'bz100: ALUout = alu_xor;
        4'bz111: ALUout = alu_and;
        4'bz110: ALUout = alu_or;
        4'b0101: ALUout = shift_right_l;
        4'b1101: ALUout = shift_right_a;
        default: ALUout = 0;
    endcase
end

endmodule

/******************************************************************************
* 下面这种写法有点问题,待解决
*******************************************************************************/
// wire [`DATA_WIDTH-1:0] C = ~B + 32'b1;
// wire [`DATA_WIDTH-1:0] shift_amount = {27'b0, B[4:0]};

// reg overflow = 0;
// reg carry = 0;
// reg  [`DATA_WIDTH-1:0] AddOut = 0;

// always @(*) begin
//     if (ALUctr == 4'b0010 || ALUctr == 4'b1010 || ALUctr == 4'b1000) begin
//         overflow = (A[`DATA_WIDTH-1] == C[`DATA_WIDTH-1]) && (AddOut[`DATA_WIDTH-1] != A[`DATA_WIDTH-1]);
//     end
//     else if (ALUctr == 4'b0000) begin
//         overflow = (A[`DATA_WIDTH-1] == B[`DATA_WIDTH-1]) && (AddOut[`DATA_WIDTH-1] != A[`DATA_WIDTH-1]);
//     end
//     else begin
//         overflow = 0;
//     end
// end

// always @(*) begin
//     if (ALUctr == 4'b0010 || ALUctr == 4'b1010 || ALUctr == 4'b1000) begin
//         {carry, AddOut} = A + C;
//     end
//     else if (ALUctr == 4'b0000) begin
//         {carry, AddOut} = A + B;
//     end
//     else begin
//         {carry, AddOut} = 0;
//     end
// end

// always @(*) begin
//     if (ALUctr == 4'b0010) begin
//         Less = overflow ^ (A[`DATA_WIDTH-1] + C[`DATA_WIDTH-1]);
//     end
//     else if (ALUctr == 4'b1010) begin
//         Less = 0 ^ carry;
//     end
//     else begin
//         Less = 0;
//     end
// end

// always @(*) begin
//     if ((ALUctr == 4'b0010 || ALUctr == 4'b1010 || ALUctr == 4'b1000) && ALUout == 0) begin
//         Zero = 1;
//     end
//     else begin
//         Zero = 0;
//     end
// end

//     always @* begin
//         casez (ALUctr)
//             4'b0000: ALUout = A + B; // 加法
//             4'b1000: ALUout = A - B; // 减法
//             4'bz001: ALUout = A << B[4:0] ; // 逻辑左移
//             4'b0010: ALUout = {31'b0, Less};    // 做减法，选择带符号小于置位结果输出, Less按带符号结果设置                          
//             4'b1010: ALUout = {31'b0, Less};   //做减法，选择无符号小于置位结果输出, Less按无符号结果设置
//             4'bz011: ALUout = B; // 选择ALU输入B的结果直接输出
//             4'bz100: ALUout = A ^ B; // 逻辑异或
//             4'bz111: ALUout = A & B; // 逻辑与
//             4'bz110: ALUout = A | B; // 逻辑或
//             4'b0101: ALUout = A >> B[4:0] ; // 逻辑右移
//             4'b1101: begin
//                 ALUout = A >> B[4:0]; // 算数右移
//                 if (A[31]) begin
//                     integer i;
                    
//                     for ( i = `DATA_WIDTH-1; i >= (`DATA_WIDTH - shift_amount) ; i = i - 1 ) begin
//                         ALUout[i] = 1;
//                     end
//                 end
//             end    
//             default: begin ALUout = 0; end // 默认情况
//         endcase

//         // if (ALUout == 0) begin
//         //     Zero = 1;
//         // end
//         // else begin
//         //     Zero = 0;
//         // end
//     end

// endmodule

