module top(
	input	wire [1:0] x0,
	input	wire [1:0] x1,
	input	wire [1:0] x2,
	input	wire [1:0] x3,
	input	wire [1:0] Y,
	output	reg  [1:0] F
);

always@(*)
	case (Y) 
		2'b00: F = x0;
		2'b01: F = x1;
		2'b10: F = x2;
		2'b11: F = x3;
	default: F = 2'b00;
	endcase


endmodule
