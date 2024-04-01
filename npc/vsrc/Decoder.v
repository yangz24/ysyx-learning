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

// import "DPI-C" function void reg_print();

always @(*) begin
    casez ({op[6:2], func3, func7[5]})
        9'b00100_000_z: begin  // addi
            ExtOp = 3'b000;
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 1'b0;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b01;
            ALUctr = 4'b0000;
        end
        9'b01101_zzz_z: begin  // lui
            ExtOp = 3'b001;
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 1'b0;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b01;
            ALUctr = 4'b0011;
        end  
        9'b00101_zzz_z: begin   // auipc
            ExtOp = 3'b001;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 1'b0;
            ALUAsrc = 1'b1;
            ALUBsrc = 2'b01;
            ALUctr = 4'b0000;
        end
        9'b11011_zzz_z: begin  // jal
            ExtOp = 3'b100;  
            RegWr = 1'b1;
            Branch = 3'b001;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 1'b0;
            ALUAsrc = 1'b1;
            ALUBsrc = 2'b10;
            ALUctr = 4'b0000;
        end
        9'b11001_000_z: begin  // jalr
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b010;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 1'b0;
            ALUAsrc = 1'b1;
            ALUBsrc = 2'b10;
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
    // reg_print();
end

    
endmodule
