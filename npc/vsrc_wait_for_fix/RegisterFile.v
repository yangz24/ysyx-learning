module RegisterFile #(ADDR_WIDTH = 5, DATA_WIDTH = 32) (
  input  wire                  Wrclk,
  input  wire [ADDR_WIDTH-1:0] Ra,  // a读地址
  input  wire [ADDR_WIDTH-1:0] Rb,  // b读地址
  input  wire [ADDR_WIDTH-1:0] Rw,  // rd写地址
  input  wire [DATA_WIDTH-1:0] busW, // rd写数据
  input  wire                  RegWr, // 写使能
//   寄存器输出
  output wire [DATA_WIDTH-1:0] busA,  
  output wire [DATA_WIDTH-1:0] busB
);

// **表示乘方操作
reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];

// 寄存器x0恒为0
always @(posedge Wrclk) begin
    rf[0] = 32'd0;
end

// 寄存器读操作
assign busA = rf[Ra];
assign busB = rf[Rb];

// 寄存器写操作
always @(posedge Wrclk) begin
    if (RegWr) rf[Rw] <= busW;
  end
  
endmodule
