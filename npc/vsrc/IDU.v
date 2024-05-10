`include "define.vh"
`include "define_pipelineregs.vh"

module IDU (
    input wire clk,
    input wire rst,
    
    // if_id register input
    input type_if_id_reg  if_id_reg,

    // write back signal for register file
    input wire wb_reg_wen,  
    input wire [`REG_ADDR_WIDTH-1:0] wb_reg_waddr, 
    input wire [`DATA_WIDTH-1:0] wb_reg_wdata, 

    // expends from if stage
    output wire [`PC_WIDTH-1:0] PC,
    output wire [`DATA_WIDTH-1:0] Instr,
    output wire [`PC_WIDTH-1:0] PC_4,    
    // control signals for pipeline registers
    output wire reg_wen,
    output wire [`REG_WRITE_BACK_SEL_LENGTH-1:0] reg_wb_sel,
    output wire aluasrc,
    output wire alubsrc,
    output wire [`ALU_CTRL_LENGTH-1:0] alu_op,
    output wire do_branch,
    output wire do_jump,
    output wire [`BRANCH_COND_LENGTH-1:0] branch_cond,
    output wire [`MEM_CTRL_LENGTH-1:0] mem_op,
    output wire mem_wen,
    output wire mem_ren,
    // immediate generator output for pipeline registers
    output wire [`DATA_WIDTH-1:0] Imm,
    // decoder output signals for pipeline registers
    output wire [`REG_ADDR_WIDTH-1:0] raddr1,
    output wire [`REG_ADDR_WIDTH-1:0] raddr2,
    output wire [`REG_ADDR_WIDTH-1:0] reg_waddr,
    // register file output signals for pipeline registers
    output wire [`DATA_WIDTH-1:0] rdata1,
    output wire [`DATA_WIDTH-1:0] rdata2
);


// decoder output signals
wire [`FUNC3_LENGTH-1:0] func3;
wire [`FUNC7_LENGTH-1:0] func7;
wire [`OPCODE_LENGTH-1:0] opcode;

// control generator output signals used in immediate generator
wire [`EXTOP_LENGTH-1:0] ExtOp;




Decoder u_Decoder(
    .Instr  (if_id_reg.Instr  ),
    .raddr1 (raddr1 ),
    .raddr2 (raddr2 ),
    .waddr  (reg_waddr  ),
    .func3  (func3  ),
    .func7  (func7  ),
    .opcode (opcode )
);

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

ImmGen u_ImmGen(
    .Instr (if_id_reg.Instr ),
    .ExtOp (ExtOp ),
    .Imm   (Imm   )
);

/******************************************** hold on pipeline signals ********************************************/
assign PC = if_id_reg.PC;
assign Instr = if_id_reg.Instr;
assign PC_4 = if_id_reg.PC_4;



endmodule
