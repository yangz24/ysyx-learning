`include "define.v"

module IFU (
    input wire clk,
    input wire rst,
    // 冒险
    // input wire PCwrite,
    // input wire if_id_write,
    input wire PCsrc,
    // 分支
    input wire BPUClearCtr,
    input wire [`DATA_WIDTH-1:0] BranchPC,
    output reg [`DATA_WIDTH-1:0] IDReg_PC,
    output reg [`DATA_WIDTH-1:0] IDReg_Instr,
    output reg [`OPCODE_WIDTH-1:0]  IDReg_op,
    output reg [`ADDR_WIDTH-1:0]    IDReg_rs1,
    output reg [`ADDR_WIDTH-1:0]    IDReg_rs2,
    output reg [`ADDR_WIDTH-1:0]    IDReg_Regrd,
    output reg [`FUNC3_WIDTH-1:0]   IDReg_Func3,
    output reg [`FUNC7_WIDTH-1:0]   IDReg_Func7,
    output reg [11:0] IDReg_csr,

    output reg if_diffen 
);

wire [`DATA_WIDTH-1:0] PC;
wire [`DATA_WIDTH-1:0] Instr;
wire [`OPCODE_WIDTH-1:0] op;
wire [`ADDR_WIDTH-1:0] rs1;
wire [`ADDR_WIDTH-1:0] rs2;
wire [`ADDR_WIDTH-1:0] rd;
wire [`FUNC3_WIDTH-1:0] func3;
wire [`FUNC7_WIDTH-1:0] func7;
wire [11:0] csr;

wire enable ;
assign enable = 1; // if_id_write;


PcGen u_PcGen(
    .clk   (clk   ),
    .rst   (rst   ),
    // .PCwrite (PCwrite),
    .PCsrc (PCsrc ),
    .BranchPC   (BranchPC   ),
    .PC    (PC    )
);


InstrMemCtrl u_InstrMemCtrl(
    .clk    (clk),
    .rst    (rst    ),
    .RdAddr (PC ),
    .Instr  (Instr  )
);

PreDecoder u_PreDecoder(
    .Instr (Instr ),
    .op    (op    ),
    .rs1   (rs1   ),
    .rs2   (rs2   ),
    .rd    (rd    ),
    .func3 (func3 ),
    .func7 (func7 ),
    .csr   (csr   )
);



always @(posedge clk ) begin
    if (rst | BPUClearCtr) begin
        IDReg_PC <= 0;
        IDReg_Instr <= 0;
        IDReg_op <= 0;
        IDReg_rs1 <= 0;
        IDReg_rs2 <= 0;
        IDReg_Regrd <= 0;
        IDReg_Func3 <= 0;
        IDReg_Func7 <= 0;
        IDReg_csr <= 0;
        if_diffen <= 0;
    end
    else if (enable) begin
        IDReg_PC <= PC;
        IDReg_Instr <= Instr;
        IDReg_op <= op;
        IDReg_rs1 <= rs1;
        IDReg_rs2 <= rs2;
        IDReg_Regrd <= rd;
        IDReg_Func3 <= func3;
        IDReg_Func7 <= func7;
        IDReg_csr   <= csr;
        if_diffen <= 1;
    end
    // else if (!enable) begin
    //     if_diffen <= 0;
    // end
end

endmodule