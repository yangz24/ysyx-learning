module ALUControl (
    input wire  [3:0] ALUctr,
    output wire [2:0] ALUctrl,
    output wire A_or_L, // 1算数运算，0逻辑运算
    output wire L_or_R, // 1左移，0右移
    output wire U_or_S, // 1无符号，0有符号
    output wire Sub_or_Add // 1 for sub, 0 for add
);
  
assign ALUctrl = ALUctr[2:0];
assign A_or_L = ALUctr == 4'b1101;
assign L_or_R = ALUctrl == 3'b001;
assign U_or_S = ALUctr == 4'b1010;
assign Sub_or_Add = ALUctr == 4'b1000 | ALUctr == 4'b0010 | ALUctr == 4'b1010;

endmodule
