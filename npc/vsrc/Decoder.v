/* 在确定指令类型后，需要生成每个指令对应的控制信号，来控制数据通路部件进行对应的动作。
控制信号生产部件(Control Signal Generator)是根据instr中的操作码opcode，及func3和func7来生成对应的控制信号的。 
其中操作码实际只有高5位有用，func7实际只有次高位有用。 生成的控制信号具体包括：

ExtOP :宽度为3bit，选择立即数产生器的输出类型 。

RegWr ：宽度为1bit，控制是否对寄存器rd进行写回，为1时写回寄存器。

ALUAsrc ：宽度为1bit，选择ALU输入端A的来源。为0时选择rs1，为1时选择PC。

ALUBsrc ：宽度为2bit，选择ALU输入端B的来源。为00时选择rs2，为01时选择imm(当是立即数移位指令时，只有低5位有效)，为10时选择常数4（用于跳转时计算返回地址PC+4）。

ALUctr ：宽度为4bit，选择ALU执行的操作 。

Branch ：宽度为3bit，说明分支和跳转的种类，用于生成最终的分支控制信号 。

MemtoReg ：宽度为1bit，选择寄存器rd写回数据来源，为0时选择ALU输出，为1时选择数据存储器输出。

MemWr ：宽度为1bit，控制是否对数据存储器进行写入，为1时写回存储器。

MemOP ：宽度为3bit，控制数据存储器读写格式，为010时为4字节读写，为001时为2字节读写带符号扩展，为000时为1字节读写带符号扩展，为101时为2字节读写无符号扩展，为100时为1字节读写无符号扩展。
*/

`include "define.v"

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
    output reg [2:0] MemOp
);

// import "DPI-C" function void reg_print();

always @(*) begin
    casez ({op[6:2], func3, func7[5]})
        // 整数运算指令
        9'b00100_000_z: begin  // addi
            ExtOp = 3'b000;
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;  // 111 代表不做任何访问内存操作
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
            MemOp = 3'b111;
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
            MemOp = 3'b111;
            ALUAsrc = 1'b1;
            ALUBsrc = 2'b01;
            ALUctr = 4'b0000;
        end
        9'b00100_010_z: begin   //slti
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b01;
            ALUctr = 4'b0010;
        end
        9'b00100_011_z: begin    // sltiu
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b01;
            ALUctr = 4'b1010;
        end
        9'b00100_100_z: begin    // xori
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b01;
            ALUctr = 4'b0100;
        end
        9'b00100_110_z: begin    // ori
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b01;
            ALUctr = 4'b0110;
        end    
        9'b00100_111_z: begin    // andi
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b01;
            ALUctr = 4'b0111;
        end     
        9'b00100_001_0: begin    // slli 逻辑左移立即数
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b01;
            ALUctr = 4'b0001;
        end   
        9'b00100_101_0: begin    // srli 逻辑右移立即数
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b01;
            ALUctr = 4'b0101;
        end  
        9'b00100_101_1: begin    // srli 算数右移立即数
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b01;
            ALUctr = 4'b1101;
        end 
        9'b01100_000_0: begin    // add
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b00;
            ALUctr = 4'b0000;
        end 
        9'b01100_000_1: begin    // sub
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b00;
            ALUctr = 4'b1000;
        end 
        9'b01100_001_0: begin    // sll
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b00;
            ALUctr = 4'b0001;
        end 
        9'b01100_010_0: begin    // slt
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b00;
            ALUctr = 4'b0010;
        end 
        9'b01100_011_0: begin    // sltu
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b00;
            ALUctr = 4'b1010;
        end 
        9'b01100_100_0: begin    // xor
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b00;
            ALUctr = 4'b0100;
        end 
        9'b01100_101_0: begin    // srl
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b00;
            ALUctr = 4'b0101;
        end 
        9'b01100_101_1: begin    // sra
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b00;
            ALUctr = 4'b1101;
        end 
        9'b01100_110_0: begin    // or
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b00;
            ALUctr = 4'b0110;
        end 
        9'b01100_111_0: begin    // and
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b00;
            ALUctr = 4'b0111;
        end 
        9'b11011_zzz_z: begin  // jal
            ExtOp = 3'b100;  
            RegWr = 1'b1;
            Branch = 3'b001;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b1;
            ALUBsrc = 2'b10;
            ALUctr = 4'b0000;
        end
        // 控制转移指令
        9'b11001_000_z: begin  // jalr
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b010;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b1;
            ALUBsrc = 2'b10;
            ALUctr = 4'b0000;
        end
        9'b11000_000_z: begin  // beq
            ExtOp = 3'b011;  
            RegWr = 1'b0;
            Branch = 3'b100;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b00;
            ALUctr = 4'b0010;
        end
        9'b11000_001_z: begin  // bne
            ExtOp = 3'b011;  
            RegWr = 1'b0;
            Branch = 3'b101;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b00;
            ALUctr = 4'b0010;
        end
        9'b11000_100_z: begin  // blt
            ExtOp = 3'b011;  
            RegWr = 1'b0;
            Branch = 3'b110;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b00;
            ALUctr = 4'b0010;
        end
        9'b11000_101_z: begin  // bge
            ExtOp = 3'b011;  
            RegWr = 1'b0;
            Branch = 3'b111;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b00;
            ALUctr = 4'b0010;
        end
        9'b11000_110_z: begin  // bltu
            ExtOp = 3'b011;  
            RegWr = 1'b0;
            Branch = 3'b110;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b00;
            ALUctr = 4'b1010;
        end
        9'b11000_111_z: begin  // bgeu
            ExtOp = 3'b011;  
            RegWr = 1'b0;
            Branch = 3'b111;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b00;
            ALUctr = 4'b1010;
        end
        // 存储器访问指令
        9'b00000_000_z: begin  // lb
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b1;
            MemWr = 1'b0;
            MemOp = 3'b000;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b01;
            ALUctr = 4'b0000;
        end
        9'b00000_001_z: begin  // lh
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b1;
            MemWr = 1'b0;
            MemOp = 3'b001;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b01;
            ALUctr = 4'b0000;
        end
        9'b00000_010_z: begin  // lw
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b1;
            MemWr = 1'b0;
            MemOp = 3'b010;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b01;
            ALUctr = 4'b0000;
        end
        9'b00000_100_z: begin  // lbu
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b1;
            MemWr = 1'b0;
            MemOp = 3'b100;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b01;
            ALUctr = 4'b0000;
        end
        9'b00000_101_z: begin  // lhu
            ExtOp = 3'b000;  
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b1;
            MemWr = 1'b0;
            MemOp = 3'b101;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b01;
            ALUctr = 4'b0000;
        end
        9'b01000_000_z: begin  // sb
            ExtOp = 3'b010;  
            RegWr = 1'b0;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b1;
            MemOp = 3'b000;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b01;
            ALUctr = 4'b0000;
        end
        9'b01000_001_z: begin  // sh
            ExtOp = 3'b010;  
            RegWr = 1'b0;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b1;
            MemOp = 3'b001;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b01;
            ALUctr = 4'b0000;
        end
        9'b01000_010_z: begin  // sw
            ExtOp = 3'b010;  
            RegWr = 1'b0;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b1;
            MemOp = 3'b010;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b01;
            ALUctr = 4'b0000;
        end
        9'b11100_001_z: begin // csrrw
            ExtOp = 3'b000;
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0; 
            ALUBsrc = 2'b00; 
            ALUctr = 4'b0000; 
        end
        9'b11100_010_z: begin // csrrs
            ExtOp = 3'b000;
            RegWr = 1'b1;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0; 
            ALUBsrc = 2'b00; 
            ALUctr = 4'b0000; 
        end
        default: begin
            ExtOp = 3'b000;
            RegWr = 1'b0;
            Branch = 3'b000;
            MemtoReg = 1'b0;
            MemWr = 1'b0;
            MemOp = 3'b111;
            ALUAsrc = 1'b0;
            ALUBsrc = 2'b00;
            ALUctr = 4'b0000;
        end
    endcase
    // reg_print();
end

    
endmodule
