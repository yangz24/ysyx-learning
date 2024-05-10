`include "define.vh"

module RegisterFile (
    input  wire                         clk                        ,
    input  wire                         rst                        ,
    // reg read
    input  wire        [`REG_ADDR_WIDTH-1:0]raddr1                     ,
    input  wire        [`REG_ADDR_WIDTH-1:0]raddr2                     ,
    // reg write
    input  wire        [`REG_ADDR_WIDTH-1:0]waddr                      ,
    input  wire        [`DATA_WIDTH-1:0]wdata                      ,
    input  wire                         wen                        ,
    //   寄存器输出
    output wire        [`DATA_WIDTH-1:0]rdata1                       ,
    output wire        [`DATA_WIDTH-1:0]rdata2                        
);


/******************************************** Register File ********************************************/
reg [`DATA_WIDTH-1:0] rf [2**`REG_ADDR_WIDTH-1:0];

/******************************************** reg read ********************************************/

// reg0 always 0
always @(posedge clk) begin
    rf[0] <= 32'd0;
end

assign rdata1 = (raddr1 == waddr && waddr != 0 && wen)?  wdata: rf[raddr1];
assign rdata2 = (raddr2 == waddr && waddr != 0 && wen)?  wdata: rf[raddr2];

/******************************************** reg write ********************************************/
always @(posedge clk) begin
    if (wen && waddr != 0) begin
      rf[waddr] <= wdata;
    end
  end


endmodule
