`include "define.v"

// module CSRRegister (
//     input wire clk,
//     input wire rst,
//     // mepc
//     input wire [`DATA_WIDTH-1:0] mepc_in,
//     input wire mepc_wr,
//     output wire [`DATA_WIDTH-1:0] mepc_out,
//     // mcause
//     input wire [`DATA_WIDTH-1:0] mcause_in,
//     input wire mcause_wr,
//     output wire [`DATA_WIDTH-1:0] mcause_out,
//     // mstatus
//     input wire [`DATA_WIDTH-1:0] mstatus_in,
//     input wire mstatus_wr,
//     output wire [`DATA_WIDTH-1:0] mstatus_out,
//     // mtvec
//     input wire [`DATA_WIDTH-1:0] mtvec_in,
//     input wire mtvec_wr,
//     output wire [`DATA_WIDTH-1:0] mtvec_out

// );

// // mepc   
// reg [`DATA_WIDTH-1:0] mepc;
// // mepc 写     
// always @(posedge clk ) begin
//     if (rst) begin
//         mepc <= 0;
//     end
//     else if(mepc_wr) begin
//         mepc <= mepc_in;
//     end
// end
// // mepc 读
// assign mepc_out = mepc;

// // mcause
// reg [`DATA_WIDTH-1:0] mcause;
// always @(posedge clk) begin
//     if (rst) begin
//         mcause <= 0;
//     end
//     else if (mcause_wr) begin
//         mcause <= mcause_in;
//     end
// end
// assign mcause_out = mcause;

// reg [`DATA_WIDTH-1:0] mstatus;
// always @(posedge clk ) begin
//     if (rst) begin
//         mstatus <= 32'h1800;
//     end
//     else if (mstatus_wr) begin
//         mstatus <= mstatus_in;
//     end
// end
// assign mstatus_out = mstatus;

// // mtvec
// reg [`DATA_WIDTH-1:0] mtvec;
// always @(posedge clk ) begin
//     if (rst) begin
//         mtvec <= 0;
//     end
//     else if (mtvec_wr) begin
//         mtvec <= mtvec_in;
//     end
// end
// assign mtvec_out = mtvec;

// endmodule



module CSRRegister (
    input wire clk,
    input wire rst,
    input wire [11:0] csrrd, // 读地址
    input wire [11:0] csrwr, //写地址
    input wire wren,
    input wire ecallwr,
    input wire ecallrd,
    input wire mret,
    input wire [63:0] ecall_package,
    input wire [`DATA_WIDTH-1:0] CSRin, // 写数据
    output wire [`DATA_WIDTH-1:0] CSRout
);

// wire [1:0] index;

// assign index = (csr == 12'h341)? 0 : // mepc
//                (csr == 12'h342)? 1 : // mcause
//                (csr == 12'h300)? 2 : // mstatus;
//                (csr == 12'h305)? 3 : 0; // mtvec;

// // CSR寄存器    
// reg [`DATA_WIDTH-1:0] CSR [3:0];

// // CSR读
// assign CSRout = CSR[index];
// // CSR写
// always @(posedge clk) begin
//     if (rst) begin
//         CSR[index] <= 0;
//     end
//     else if(wren) begin
//         CSR[index] = CSRin;
//     end
// end

reg [`DATA_WIDTH-1:0] mepc;
reg [`DATA_WIDTH-1:0] mcause;
reg [`DATA_WIDTH-1:0] mstatus;
reg [`DATA_WIDTH-1:0] mtvec;

// mepc 写
always @(posedge clk ) begin
    if (rst) begin
        mepc <= 0;
    end
    else if (wren && csrwr == 12'h341) begin
        mepc <= CSRin;
    end
    else if (ecallwr) begin
        mepc <= ecall_package[31:0];
    end
end

// mcause 写
always @(posedge clk ) begin
    if (rst) begin
        mcause <= 0;
    end
    else if (wren && csrwr == 12'h342) begin
        mcause <= CSRin;
    end
    else if (ecallwr) begin
        mcause <= ecall_package[63:32];
    end
end

// mstaus 写
always @(posedge clk ) begin
    if (rst) begin
        mstatus <= 32'h1800;
    end
    else if (wren && csrwr == 12'h300) begin
        mstatus <= CSRin;
    end
end

// mtvec 写
always @(posedge clk ) begin
    if (rst) begin
        mtvec <= 0;
    end
    else if (wren && csrwr == 12'h305) begin
        mtvec <= CSRin;
    end
end

// CSR读
assign CSRout = (csrrd == 12'h341 | mret)? mepc :
                (csrrd == 12'h342)? mcause :
                (csrrd == 12'h300)? mstatus :
                (csrrd == 12'h305 | ecallrd )? mtvec : 0;

endmodule