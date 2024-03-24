module Decoder ( 
    input wire [6:0] op,
    input wire [2:0] func3,
    input wire [6:0] func7,
    output reg [2:0] ExtOp,
    output reg  RegWr,
    output reg  ALUAsrc,
    output reg [1:0] ALUBsrc,
    output reg [3:0] ALUctr,
    output reg [2:0] Branch,
    output reg  MemtoReg,
    output reg  MemWr,
    output reg  MemOp
);

always @(*) begin
    casez ({op, func3, func7[5]})
        11'b00100zzzzzz: begin  // addi
            ExtOp = 3'b000;
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 1'bz;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b01;
            ALUctr = 4'b0000;
        end  
        default: begin
            ExtOp = 3'b000;
            RegWr = 1'b0;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 1'b0;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b00;
            ALUctr = 4'b0000;
        end
    endcase
end

    
endmodule
