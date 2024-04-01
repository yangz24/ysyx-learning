module ALU #( DATA_WIDTH = 32) (
    input [DATA_WIDTH-1:0] A, // 操作数1
    input [DATA_WIDTH-1:0] B, // 操作数2
    input [3:0] ALUctr, // ALU 控制信号，用于选择ALU的具体操作
    output reg zero, // 零标志位，如果结果为零则置1
    output reg [DATA_WIDTH-1:0] ALUout // ALU的计算结果
);

wire [DATA_WIDTH-1:0] shift_amount = {27'b0, B[4:0]};
    always @* begin
        case (ALUctr)
            4'b0000: ALUout = A + B; // 加法
            4'b1000: ALUout = A - B; // 减法
            4'b111: ALUout = A & B; // 逻辑与
            4'b110: ALUout = A | B; // 逻辑或
            4'b100: ALUout = A ^ B; // 逻辑异或
            4'b001: ALUout = A << B[4:0] ; // 逻辑左移
            4'b0101: ALUout = A >> B[4:0] ; // 逻辑右移
            4'b1101: begin
                ALUout = A >> B[4:0];
                if (A[31]) begin
                    integer i;
                    
                    for ( i = DATA_WIDTH-1; i >= (DATA_WIDTH - shift_amount) ; i = i - 1 ) begin
                        ALUout[i] = 1;
                    end
                end
            end    
            default: ALUout = 0; // 默认情况
        endcase

        if (ALUout == 0) begin
            zero = 1;
        end
        else begin
            zero = 0;
        end
    end

endmodule

