module BarrelShifter #(
    DATA_WIDTH = 32
) (
    input wire [DATA_WIDTH-1:0] Din,
    input wire [4:0]            Shamt,
    input wire                  L_or_R,
    input wire                  A_or_L, 
    output wire [DATA_WIDTH-1:0] Dout
);

reg [DATA_WIDTH-1:0] temp ;

always @(*) begin
    case ({A_or_L, L_or_R})
    // 算术移位要保证符号位不改变，算术左移同逻辑左移一样，算术右移最左面的空位补符号位。
        2'b01, 2'b11: begin
            temp = Shamt[0]? {Din[DATA_WIDTH-2:0], 1'b0} : Din;
            temp = Shamt[1]? {temp[DATA_WIDTH-3:0], 2'b0} : temp;
            temp = Shamt[2]? {temp[DATA_WIDTH-5:0], 4'b0} : temp;
            temp = Shamt[3]? {temp[DATA_WIDTH-9:0], 8'b0} : temp;
            temp = Shamt[4]? {temp[DATA_WIDTH-17:0], 16'b0} : temp;
            end 
    // 逻辑右移
        2'b00: begin
            temp = Shamt[0]? {1'b0, Din[DATA_WIDTH-1:1]} : Din;
            temp = Shamt[1]? {2'b0, temp[DATA_WIDTH-1:2]} : temp;
            temp = Shamt[2]? {4'b0, temp[DATA_WIDTH-1:4]} : temp;
            temp = Shamt[3]? {8'b0, temp[DATA_WIDTH-1:8]} : temp;
            temp = Shamt[4]? {16'b0, temp[DATA_WIDTH-1:16]} : temp;
            end
    // 算数右移
        2'b10: begin
            temp = Shamt[0]? {Din[DATA_WIDTH-1], Din[DATA_WIDTH-1:1]} : Din;
            temp = Shamt[1]? {{2{temp[DATA_WIDTH-1]}}, temp[DATA_WIDTH-1:2]} : temp;
            temp = Shamt[2]? {{4{temp[DATA_WIDTH-1]}}, temp[DATA_WIDTH-1:4]} : temp;
            temp = Shamt[3]? {{8{temp[DATA_WIDTH-1]}}, temp[DATA_WIDTH-1:8]} : temp;
            temp = Shamt[4]? {{16{temp[DATA_WIDTH-1]}}, temp[DATA_WIDTH-1:16]} : temp;
        end
        default: temp = 32'b0;
    endcase
end

assign Dout = temp;

endmodule
