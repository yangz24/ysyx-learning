`include "define.vh"
`include "define_pipelineregs.vh"

module IDU (
    input wire clk,
    input wire rst,
    
    // if_id_bus input
    input [`IF_ID_BUS_WIDTH-1:0] if_id_bus,

    // // if_id_reg enable update
    // input wire if_id_reg_enable,

    // hazard detected flag
    input wire hazard_detected,

    // BPU clear control signal
    input wire bpu_clear_ctrl,

    // write back signal for register file
    input wire wb_reg_wen,  
    input wire [`REG_ADDR_WIDTH-1:0] wb_reg_waddr, 
    input wire [`DATA_WIDTH-1:0] wb_reg_wdata, 

    // for hazard detection
    output wire [`REG_ADDR_WIDTH-1:0] if_id_reg_raddr1,
    output wire [`REG_ADDR_WIDTH-1:0] if_id_reg_raddr2,

    // handshake signals with last stage
    input wire s_valid,
    output wire s_ready,

    // handshake signals with next stage
    output reg m_valid,
    input wire m_ready,

    // id_exe_bus output
    output wire [`ID_EXE_BUS_WIDTH-1:0] id_exe_bus
);


/******************************************** if_id_reg pipeline registers ********************/
reg [`IF_ID_BUS_WIDTH-1:0] if_id_reg;

/******************************************** internal use signals ********************************************/
// decoder output signals
wire [`FUNC3_LENGTH-1:0] func3;
wire [`FUNC7_LENGTH-1:0] func7;
wire [`OPCODE_LENGTH-1:0] opcode;

// control generator output signals used in immediate generator
wire [`EXTOP_LENGTH-1:0] ExtOp;

/******************************************** id_exe_bus signals ********************************************/
// expends from if stage
wire [`PC_WIDTH-1:0] PC;
wire [`DATA_WIDTH-1:0] Instr;
wire [`PC_WIDTH-1:0] PC_4;
// control signals from control unit
wire reg_wen;
wire [`REG_WRITE_BACK_SEL_LENGTH-1:0] reg_wb_sel;
wire aluasrc;
wire alubsrc;
wire [`ALU_CTRL_LENGTH-1:0] alu_op;
wire do_branch;
wire do_jump;
wire [`BRANCH_COND_LENGTH-1:0] branch_cond;
wire [`MEM_CTRL_LENGTH-1:0] mem_op;
wire mem_wen;
wire mem_ren;
// immediate value from imm generator
wire [`DATA_WIDTH-1:0] imm;
// decoder output for regfile
wire [`REG_ADDR_WIDTH-1:0] raddr1;
wire [`REG_ADDR_WIDTH-1:0] raddr2;
wire [`REG_ADDR_WIDTH-1:0] reg_waddr;
// register file output
wire [`DATA_WIDTH-1:0] rdata1;
wire [`DATA_WIDTH-1:0] rdata2;

// for debug
// wire diffen;

/******************************************** handshake ********************************************/
wire ready_go = ~hazard_detected; // all task in this stage is done, all data is prepared, ready to go
reg s_valid_r; // reg from last stage, flag to indicate data from lastis valid or not
wire pipe_is_valid; // pipeline is real valid

assign s_ready = ~pipe_is_valid || (m_ready && ready_go);
assign m_valid = pipe_is_valid && ready_go;
assign pipe_is_valid = s_valid_r && ~bpu_clear_ctrl;

always @(posedge clk ) begin
    if (rst) begin
        s_valid_r <= 0;
    end
    else if (s_ready) begin
        s_valid_r <= s_valid;
    end
end

// always @(posedge clk ) begin
//     if (rst || bpu_clear_ctrl) begin
//         if_id_reg <= 0;
//     end
//     else if (if_id_reg_enable) begin
//         if_id_reg <= if_id_bus;
//     end
// end

always @(posedge clk ) begin
    if (rst) begin
        if_id_reg <= 0;
    end
    else if(s_valid && s_ready) begin
        if_id_reg <= if_id_bus;
    end
end

assign {
    PC,
    Instr,
    PC_4
    // diffen
} = if_id_reg;

/******************************************** decoder ********************************************/
Decoder u_Decoder(
    .Instr  (Instr  ),
    .raddr1 (raddr1 ),
    .raddr2 (raddr2 ),
    .waddr  (reg_waddr  ),
    .func3  (func3  ),
    .func7  (func7  ),
    .opcode (opcode )
);

/******************************************** control generator ********************************************/
ControlGen u_ControlGen(
    .func3       (func3       ),
    .func7       (func7       ),
    .opcode      (opcode      ),
    .ExtOp       (ExtOp       ),
    .reg_wen     (reg_wen     ),
    .reg_wb_sel  (reg_wb_sel  ),
    .aluasrc     (aluasrc     ),
    .alubsrc     (alubsrc     ),
    .alu_op      (alu_op      ),
    .do_branch   (do_branch   ),
    .do_jump     (do_jump     ),
    .branch_cond (branch_cond ),
    .mem_op      (mem_op      ),
    .mem_wen     (mem_wen     ),
    .mem_ren     (mem_ren     )
);

/******************************************** register file **********/
RegisterFile u_RegisterFile(
    .clk    (clk    ),
    .rst    (rst    ),
    .raddr1 (raddr1 ),
    .raddr2 (raddr2 ),
    .waddr  (wb_reg_waddr  ),
    .wdata  (wb_reg_wdata  ),
    .wen    (wb_reg_wen    ),
    .rdata1   (rdata1   ),
    .rdata2   (rdata2   )
);

/******************************************** imm generator **********/
ImmGen u_ImmGen(
    .Instr (Instr ),
    .ExtOp (ExtOp ),
    .Imm   (imm   )
);

/******************************************** for hazard detection ********************************************/
assign if_id_reg_raddr1 = pipe_is_valid? raddr1 : 0;
assign if_id_reg_raddr2 = pipe_is_valid? raddr2 : 0;

/******************************************** for BPU ********************************************/


/******************************************** id_exe_bus output ********************************************/
assign id_exe_bus = {
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
};



endmodule
