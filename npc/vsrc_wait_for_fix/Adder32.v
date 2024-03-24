module Adder32 #(
    parameter DATA_WIDTH = 32
) (
    input wire [DATA_WIDTH-1:0] A,
    input wire [DATA_WIDTH-1:0] B,
    input wire                  Cin, 
    output wire                 Carry,
    output wire                 Zero,
    output wire                 Overflow,
    output wire [DATA_WIDTH-1:0] Result 
);

wire [DATA_WIDTH-1:0] C;
assign C[0] = Cin;

genvar i;
generate
    for (i = 0; i < DATA_WIDTH - 1; i = i + 1) begin : fa_loop
       Full_Adder u_Full_Adder(
        .A    	( A[i]     ),
        .B    	( B[i]     ),
        .Cin  	( C[i]     ),
        .Sum  	( Result[i]),
        .Cout 	( C[i+1]   )
       );
        
    end
endgenerate

assign Result[DATA_WIDTH-1] = A[DATA_WIDTH-1] + B[DATA_WIDTH-1];
assign Carry = C[DATA_WIDTH-1];
assign Overflow = ((A[DATA_WIDTH-1] == B[DATA_WIDTH-1]) && (Result[DATA_WIDTH-1] != A[DATA_WIDTH-1]));
assign Zero = ~(|Result);
    
endmodule
