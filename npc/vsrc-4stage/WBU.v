`include "define.v"

module WBU (
    input wire clk,
    input wire rst,
    // control signals input
    input wire WBReg_MemtoReg,
    input wire WBReg_RegWr, // 写回寄存器使能
    // data input
    input wire [`ADDR_WIDTH-1:0] WBReg_Regrd, // 写回寄存器地址
    input wire [`DATA_WIDTH-1:0] WBReg_ALUout,
    input wire [`DATA_WIDTH-1:0] WBReg_DataOut,
    input wire [`DATA_WIDTH-1:0] WBReg_CSRout,
    input wire WBReg_CSRRegvalid,
    input wire WBReg_CSRRegWr,
    input wire WBReg_CSRset,
    input wire WBReg_ecall,
    input wire [63:0] WBReg_ecall_package,
    // input wire WBReg_mret,
    input wire [11:0] WBReg_csr,
    input wire [`DATA_WIDTH-1:0] WBReg_ALUa,
    // PC input
    input wire [`DATA_WIDTH-1:0] WBReg_PC,
    // Instr input
    input wire [`DATA_WIDTH-1:0] WBReg_Instr,
    // diffen
    input wire ex_diffen,
    input wire WBReg_PCsrc,
    // control signals output
    output reg HoldOnRegWr, // 写回寄存器使能
    output reg [`ADDR_WIDTH-1:0] Rw, // 写回寄存器地址
    // data output
    output reg [`DATA_WIDTH-1:0] busW, // 写回寄存器数据
    output reg [`DATA_WIDTH-1:0] CSRin, // CSR寄存器写回数据
    output reg CSRWren,
    output reg ecallen,
    output reg [63:0] ecall_packageen,
    // output reg mreten,
    output reg [11:0] Reg_csren,
    // PC output
    output reg [`DATA_WIDTH-1:0] HoldPC,
    // Instr output
    output reg [`DATA_WIDTH-1:0] HoldInstr,

    output reg wb_diffen,
    output reg HoldPCsrc

);
    
wire enable = 1;


assign Rw = WBReg_Regrd;
assign HoldOnRegWr = WBReg_RegWr;

// 寄存器写回来源选择模块
assign busW = WBReg_MemtoReg? WBReg_DataOut : 
              WBReg_CSRRegvalid? WBReg_CSRout  : WBReg_ALUout;

assign CSRin = WBReg_CSRset? WBReg_CSRout | WBReg_ALUa  : WBReg_ALUa;
assign CSRWren = WBReg_CSRRegWr;
assign ecallen = WBReg_ecall;
assign ecall_packageen = WBReg_ecall_package;
// assign mreten = WBReg_mret;
assign Reg_csren = WBReg_csr;

always @(posedge clk ) begin
    if (rst) begin
        HoldPC <= 0;
        HoldInstr <= 0;
        wb_diffen <= 0;
        HoldPCsrc <= 0;
    end
    else if (enable) begin
        HoldPC <= WBReg_PC;
        HoldInstr <= WBReg_Instr;
        wb_diffen <= ex_diffen;
        HoldPCsrc <= WBReg_PCsrc;
    end
end



import "DPI-C" function void npc_trap();
always @(posedge clk) begin
    case (WBReg_Instr)
        32'b00000000000100000000000001110011: begin npc_trap(); end    // ebreak
        default:;
    endcase
end

endmodule