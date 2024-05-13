`include "define.vh"
`include "define_pipelineregs.vh"

module EXU (
    input wire clk,
    input wire rst,

    // id_exe_bus input
    input wire [`ID_EXE_BUS_WIDTH-1:0] id_exe_bus,

    // // flush pipeline registers 
    // input wire hazard_clear_ctrl,

    // bpu flush pipeline registers
    input wire bpu_clear_ctrl,

    // forwarding selection
    input [`FORWARDING_A_LENGTH-1:0] forwardingA,
    input [`FORWARDING_B_LENGTH-1:0] forwardingB,

    // forwarding data
    input [`DATA_WIDTH-1:0] exe_mem_reg_alu_out,
    input [`DATA_WIDTH-1:0] wb_reg_wdata,

    // branch judgement output
    output wire branch_taken,
    output wire [`PC_WIDTH-1:0] branch_PC,

    // for forwarding detection
    output wire [`REG_ADDR_WIDTH-1:0] id_exe_reg_raddr1,
    output wire [`REG_ADDR_WIDTH-1:0] id_exe_reg_raddr2,

    // for hazard detection
    output wire id_exe_reg_mem_ren,
    output wire [`REG_ADDR_WIDTH-1:0] id_exe_reg_waddr,

    // for difftest
    output wire [`PC_WIDTH-1:0] id_exe_reg_PC,

    // handshake signals with last stage
    input wire s_valid,
    output wire s_ready,

    // handshake signals with next stage
    output reg m_valid,
    input wire m_ready,

    // exe_mem_bus output
    output wire [`EXE_MEM_BUS_WIDTH-1:0] exe_mem_bus

);

/******************************************** id_exe_reg pipeline register ***********************************************/
reg [`ID_EXE_BUS_WIDTH-1:0] id_exe_reg;

/******************************************** internal used signals ********************************************/
// real rs1 and rs2
wire [`DATA_WIDTH-1:0] rs1;

// alu source selection
wire aluasrc;
wire alubsrc;

// alu operation selection
wire [`ALU_CTRL_LENGTH-1:0] alu_op;
// alu source
wire [`DATA_WIDTH-1:0] A;
wire [`DATA_WIDTH-1:0] B;

// conditional branch judgement output
wire cond_branch_taken;

// branch control signals
wire do_branch;
wire do_jump;
wire [`BRANCH_COND_LENGTH-1:0] branch_cond;

// immediate value
wire [`DATA_WIDTH-1:0] imm;

// register address for rs1 and rs2
wire [`REG_ADDR_WIDTH-1:0] raddr1;
wire [`REG_ADDR_WIDTH-1:0] raddr2;

// register data for rs1 and rs2
wire [`DATA_WIDTH-1:0] rdata1;
wire [`DATA_WIDTH-1:0] rdata2;

// reserved for future use
wire Zero;
wire Less;

/******************************************** exe_mem_bus signals ********************************************/
// expends from id stage
wire [`PC_WIDTH-1:0] PC;
wire [`DATA_WIDTH-1:0] Instr;
wire [`PC_WIDTH-1:0] PC_4;
// control signals hold from id stage
wire reg_wen;
wire [`REG_WRITE_BACK_SEL_LENGTH-1:0] reg_wb_sel;
wire [`MEM_CTRL_LENGTH-1:0] mem_op;
wire mem_wen;
wire mem_ren;
// decoder output for regfile
wire [`REG_ADDR_WIDTH-1:0] reg_waddr;
// alu output
wire [`DATA_WIDTH-1:0] alu_out;
// rs2 for memory datain
wire [`DATA_WIDTH-1:0] rs2;

// for debug
// wire diffen;

/******************************************** handshake ********************************************/
wire ready_go = 1'b1; // data is prepared, ready to go
reg s_valid_r;
reg pipe_is_valid; // pipeline is valid, reg from last stage

assign s_ready = ~pipe_is_valid || (m_ready && ready_go);
assign m_valid = pipe_is_valid && ready_go;
assign pipe_is_valid = s_valid_r;

always @(posedge clk ) begin
    if (rst) begin
        s_valid_r <= 0;
    end
    else if (s_ready) begin
        s_valid_r <= s_valid;
    end
end

// always @(posedge clk) begin
//     if (rst || hazard_clear_ctrl || bpu_clear_ctrl) begin
//         id_exe_reg <= 0;
//     end
//     else begin
//         id_exe_reg <= id_exe_bus;
//     end
// end

always @(posedge clk ) begin
    if (rst) begin
        id_exe_reg <= 0;
    end
    else if (s_valid && s_ready) begin
        id_exe_reg <= id_exe_bus;
    end
end

assign {
    PC,
    Instr,
    PC_4,
    reg_wen,
    reg_wb_sel,
    aluasrc,
    alubsrc,
    alu_op,
    do_branch,
    do_jump,
    branch_cond,
    mem_op,
    mem_wen,
    mem_ren,
    imm,
    raddr1,
    raddr2,
    reg_waddr,
    rdata1,
    rdata2
    // diffen
} = id_exe_reg;

/******************************************** for forwarding detection ********************************************/
assign id_exe_reg_raddr1 = pipe_is_valid? raddr1 : 0;
assign id_exe_reg_raddr2 = pipe_is_valid? raddr2 : 0;
/******************************************** forwarding ********************************************/

assign rs1 = (forwardingA == `FORWARDING_A_EXE_MEM)? exe_mem_reg_alu_out : // rs1 is from last alu output
             (forwardingA == `FORWARDING_A_MEM_WB)? wb_reg_wdata : // rs1 is from mem_wb_reg
             rdata1; // rs1 is from id_exe_reg

assign rs2 = (forwardingB == `FORWARDING_B_EXE_MEM)? exe_mem_reg_alu_out : // rs1 is from last alu output
             (forwardingB == `FORWARDING_B_MEM_WB)? wb_reg_wdata : // rs1 is from mem_wb_reg
             rdata2; // rs1 is from id_exe_reg

/******************************************** alu module ********************************************/

assign A = (aluasrc == `ALU_ASRC_RS1)? rs1 : PC;
assign B = (alubsrc == `ALU_BSRC_RS2)? rs2 : imm;

ALU u_ALU(
    .A                                 (A                         ),
    .B                                 (B                         ),
    .alu_op                            (alu_op                    ),
    .Zero                              (Zero                      ),
    .Less                              (Less                      ),
    .alu_out                           (alu_out                   ) 
);

/******************************************** branch judgement ********************************************/

Branch u_Branch(
    .branch_op                         (branch_cond               ),
    .rs1                               (rs1                       ),
    .rs2                               (rs2                       ),
    .cond_branch_taken                 (cond_branch_taken         ) 
);

assign branch_taken = pipe_is_valid? ((do_branch & cond_branch_taken) | do_jump) : 1'b0;
assign branch_PC = pipe_is_valid? alu_out : 0;

/******************************************** for hazard detection ********************************************/
assign id_exe_reg_mem_ren = pipe_is_valid? mem_ren : 0;
assign id_exe_reg_waddr = pipe_is_valid? reg_waddr : 0;

/******************************************** for difftest ********************************************/
assign id_exe_reg_PC = pipe_is_valid? PC : 0;
/******************************************** exe_mem_bus output ********************************************/
assign exe_mem_bus = {
    PC,
    Instr,
    PC_4,
    reg_wen,
    reg_wb_sel,
    mem_op,
    mem_wen,
    mem_ren,
    reg_waddr,
    alu_out,
    rs2,
    // diffen,
    branch_taken
};

endmodule