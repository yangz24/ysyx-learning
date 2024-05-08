`include "define.v"

module DataMemCtrl (
    input wire clk,
    input wire rst,
    input wire [`DATA_WIDTH-1:0] addr,
    input wire [2:0] mem_op,
    input wire mem_wen,
    input wire mem_ren,
    input wire [`DATA_WIDTH-1:0] data_in,
    output reg [`DATA_WIDTH-1:0] data_out
);

reg [`DATA_WIDTH-1:0] data_out_temp;

import "DPI-C" function int mem_read(input int addr, input int isInstr);
import "DPI-C" function void mem_write(input int addr, input int data_in, input byte Wmask);

always @(negedge clk ) begin
    if (rst) begin
        data_out_temp = 0;
        data_out = 0;
    end
    else if (mem_ren) begin
        case (mem_op)
            `MEM_CTRL_LOAD_WORD: begin data_out_temp = 0; data_out = mem_read(addr, 0); end
            `MEM_CTRL_LOAD_HALFWORD: begin data_out_temp = mem_read(addr, 0); data_out = {{16{data_out_temp[15]}}, data_out_temp[15:0]};                           end
            `MEM_CTRL_LOAD_BYTE: begin data_out_temp = mem_read(addr, 0); data_out = {{24{data_out_temp[7]}}, data_out_temp[7:0]};                             end
            `MEM_CTRL_LOAD_HALFWORD_U: begin data_out_temp = mem_read(addr, 0); data_out = {16'b0, data_out_temp[15:0]};                                          end
            `MEM_CTRL_LOAD_BYTE_U: begin data_out_temp = mem_read(addr, 0); data_out = {24'b0, data_out_temp[7:0]};                                           end
            default: begin data_out_temp = 0; data_out = 0; end
        endcase
    end
end

always @(negedge clk) begin
    if (rst) begin
    end
    else if (mem_wen) begin
        case (mem_op)
            `MEM_CTRL_STORE_WORD: mem_write(addr, data_in, 8'hff);
            `MEM_CTRL_STORE_HALFWORD: mem_write(addr, data_in, 8'h3);
            `MEM_CTRL_STORE_BYTE: mem_write(addr, data_in, 8'h1);
            default: ;
        endcase
    end
end

endmodule



