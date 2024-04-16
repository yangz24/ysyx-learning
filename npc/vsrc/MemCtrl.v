`include "define.v"

module MemCtrl (
    input wire clk,
    input wire rst,
    input wire [`DATA_WIDTH-1:0] Addr,
    input wire [2:0] MemOp,
    input wire MemWr,
    input wire MemRd,
    input wire [`DATA_WIDTH-1:0] DataIn,
    output reg [`DATA_WIDTH-1:0] DataOut
);

reg [`DATA_WIDTH-1:0] DataOutTmp;

import "DPI-C" function int mem_read(input int Addr, input int isInstr);
import "DPI-C" function void mem_write(input int Addr, input int DataIn, input byte Wmask);

always @(negedge clk) begin // negedge clk) begin
    if (rst) begin
        DataOutTmp = 0;
        DataOut = 0;
    end
    else if (MemOp == 3'b010) begin // 4字节读写
        if (MemRd) begin
            DataOutTmp = 0;
            DataOut = mem_read(Addr, 0);
        end
        if (MemWr) begin // 有写请求时
            mem_write(Addr, DataIn, 8'hf);
        end
    end
    else if (MemOp == 3'b001) begin  // 2字节读写带符号扩展
        if (MemRd) begin
            DataOutTmp = mem_read(Addr, 0);
            DataOut = {{16{DataOutTmp[15]}}, DataOutTmp[15:0]};
        end
        if (MemWr) begin
            mem_write(Addr, DataIn, 8'h3);
        end
    end
    else if (MemOp == 3'b000) begin //1字节读写带符号扩展
        if (MemRd) begin
            DataOutTmp = mem_read(Addr, 0);
            DataOut = {{24{DataOutTmp[7]}}, DataOutTmp[7:0]};            
        end
        if (MemWr) begin
            mem_write(Addr, DataIn, 8'h1);
        end
    end
    else if (MemOp == 3'b101) begin // 2字节读写无符号扩展
        if (MemRd) begin
            DataOutTmp = mem_read(Addr, 0);
            DataOut = {16'b0, DataOutTmp[15:0]};            
        end

        if (MemWr) begin
            mem_write(Addr, DataIn, 8'h3);
        end
    end
    else if (MemOp == 3'b100) begin // 1字节读写无符号扩展
        if (MemRd) begin
            DataOutTmp = mem_read(Addr, 0);
            DataOut = {24'b0, DataOutTmp[7:0]};            
        end
        if (MemWr) begin
            mem_write(Addr, DataIn, 8'h1);
        end
    end
    else begin
        DataOutTmp = 0;
        DataOut = 0;
    end
end

// always @(negedge clk ) begin
//     if (rst) begin
//         DataOutTmp = 0;
//         DataOut = 0;
//     end
//     else if (MemRd) begin
//         case (MemOp)
//             3'b010: begin DataOutTmp = 0; DataOut = mem_read(Addr, 0); end
//             3'b001: begin DataOutTmp = mem_read(Addr, 0); DataOut = {{16{DataOutTmp[15]}}, DataOutTmp[15:0]};                           end
//             3'b000: begin DataOutTmp = mem_read(Addr, 0); DataOut = {{24{DataOutTmp[7]}}, DataOutTmp[7:0]};                             end
//             3'b101: begin DataOutTmp = mem_read(Addr, 0); DataOut = {16'b0, DataOutTmp[15:0]};                                          end
//             3'b110: begin DataOutTmp = mem_read(Addr, 0); DataOut = {24'b0, DataOutTmp[7:0]};                                           end
//             default: begin DataOutTmp = 0; DataOut = 0; end
//         endcase
//     end
// end

// always @(negedge clk) begin
//     if (rst) begin
//     end
//     else if (MemWr) begin
//         case (MemOp)
//             3'b010: mem_write(Addr, DataIn, 8'hf);
//             3'b001: mem_write(Addr, DataIn, 8'h3);
//             3'b000: mem_write(Addr, DataIn, 8'h1);
//             3'b101: mem_write(Addr, DataIn, 8'h3);
//             3'b110: mem_write(Addr, DataIn, 8'h1);
//             default: ;
//         endcase
//     end
// end

endmodule



