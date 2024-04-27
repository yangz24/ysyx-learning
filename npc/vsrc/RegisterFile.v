`include "define.v"

module RegisterFile (
  input  wire                  Wrclk,
  input  wire [`ADDR_WIDTH-1:0] Ra,  // a读地址
  input  wire [`ADDR_WIDTH-1:0] Rb,  // b读地址
  input  wire [`ADDR_WIDTH-1:0] Rw,  // rd写地址
  input  wire [`DATA_WIDTH-1:0] busW, // rd写数据
  input  wire                  RegWr, // 写使能
//   寄存器输出
  output wire [`DATA_WIDTH-1:0] busA,  
  output wire [`DATA_WIDTH-1:0] busB
);

// **表示乘方操作, 这里是通用寄存器堆
reg [`DATA_WIDTH-1:0] rf [2**`ADDR_WIDTH-1:0];

// 寄存器x0恒为0
always @(posedge Wrclk) begin
    rf[0] <= 32'd0;
end

// 寄存器读操作
assign busA = (Ra == Rw && Ra != 0 && RegWr)?  busW: rf[Ra];
assign busB = (Rb == Rw && Rb != 0 && RegWr)?  busW: rf[Rb];

// 寄存器写操作
always @(posedge Wrclk) begin
    if (RegWr && Rw != 0) begin
      rf[Rw] <= busW;
    end
  end


endmodule
