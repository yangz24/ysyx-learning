`include "define.vh"
`include "define_pipelineregs.vh"

module CPU (
    input wire clk,
    input wire rst

);

/******************************************** IFU output ********************************************/
wire [`PC_WIDTH-1:0] if_id_PC;
wire [`INSTR_WIDTH-1:0] if_id_Instr;
wire [`PC_WIDTH-1:0] if_id_PC_4;

/******************************************** IF_ID_REG output **********/
type_if_id_reg if_id_reg;

/******************************************** IDU output ********************************************/
wire [`PC_WIDTH-1:0] id_exe_PC;
wire [`INSTR_WIDTH-1:0] id_exe_Instr;
wire [`PC_WIDTH-1:0] id_exe_PC_4;
wire  id_exe_reg_wen    ; 
wire [`REG_WRITE_BACK_SEL_LENGTH-1:0] id_exe_reg_wb_sel ; 
wire  id_exe_aluasrc    ; 
wire  id_exe_alubsrc    ; 
wire [`ALU_CTRL_LENGTH-1:0] id_exe_alu_op     ; 
wire  id_exe_do_branch  ; 
wire  id_exe_do_jump    ; 
wire [`BRANCH_COND_LENGTH-1:0] id_exe_branch_cond; 
wire [`MEM_CTRL_LENGTH-1:0] id_exe_mem_op     ; 
wire  id_exe_mem_wen    ; 
wire  id_exe_mem_ren    ; 
wire [`DATA_WIDTH-1:0] id_exe_Imm        ; 
wire [`REG_ADDR_WIDTH-1:0] id_exe_raddr1     ; 
wire [`REG_ADDR_WIDTH-1:0] id_exe_raddr2     ; 
wire [`REG_ADDR_WIDTH-1:0] id_exe_reg_waddr      ; 
wire [`DATA_WIDTH-1:0] id_exe_rdata1     ; 
wire [`DATA_WIDTH-1:0] id_exe_rdata2     ;

/******************************************** ID_EXE_REG output ********************************************/
type_id_exe_reg id_exe_reg;

/******************************************** EXU output **********/
wire branch_taken;
wire [`PC_WIDTH-1:0] exe_mem_PC;
wire [`INSTR_WIDTH-1:0] exe_mem_Instr;
wire [`PC_WIDTH-1:0] exe_mem_PC_4;
wire  exe_mem_reg_wen    ; 
wire [`REG_WRITE_BACK_SEL_LENGTH-1:0] exe_mem_reg_wb_sel ; 
wire [`MEM_CTRL_LENGTH-1:0] exe_mem_mem_op     ; 
wire  exe_mem_mem_wen    ; 
wire  exe_mem_mem_ren    ; 
wire [`REG_ADDR_WIDTH-1:0] exe_mem_reg_waddr      ; 
wire [`DATA_WIDTH-1:0] exe_mem_alu_out    ; 
wire [`DATA_WIDTH-1:0] exe_mem_rs2        ;

/******************************************** EXE_MEM_REG output **********/
type_exe_mem_reg exe_mem_reg;

/******************************************** MEMU output **********/
wire [`PC_WIDTH-1:0] mem_wb_PC;
wire [`INSTR_WIDTH-1:0] mem_wb_Instr;
wire [`PC_WIDTH-1:0] mem_wb_PC_4;
wire  mem_wb_reg_wen    ; 
wire [`REG_WRITE_BACK_SEL_LENGTH-1:0] mem_wb_reg_wb_sel ;
wire [`REG_ADDR_WIDTH-1:0] mem_wb_reg_waddr      ; 
wire [`DATA_WIDTH-1:0] mem_wb_alu_out    ; 
wire [`DATA_WIDTH-1:0] mem_wb_mem_out    ;


/********** MEM_WB_REG output **********/
type_mem_wb_reg mem_wb_reg;

/********** WBU output **********/
wire reg_wen;
wire [`REG_ADDR_WIDTH-1:0] reg_waddr;
wire [`DATA_WIDTH-1:0] reg_wdata;

/********** Forwarding Unit output **********/
wire [`FORWARDING_A_LENGTH-1:0] forwardingA;
wire [`FORWARDING_B_LENGTH-1:0] forwardingB;

/********** Hazard Detection Unit output **********/
wire PC_enable;
wire if_id_reg_enable;
wire hazard_clear_ctr;

/********** BPU output **********/
wire bpu_clear_ctr;


IFU u_IFU(
    .clk          (clk          ),
    .rst          (rst          ),
    .branch_taken (branch_taken ),
    .BranchPC     (exe_mem_alu_out     ),
    .PC_enable    (PC_enable    ),
    // Outputs
    .PC           (if_id_PC),
    .Instr        (if_id_Instr        ),
    .PC_4         (if_id_PC_4         )
);

IF_ID_REG  IF_ID_REG_inst (
    .clk(clk),
    .rst(rst),
    .PC(if_id_PC),
    .Instr(if_id_Instr),
    .PC_4(if_id_PC_4),
    .if_id_reg_enable(if_id_reg_enable),
    .bpu_clear_ctrl(bpu_clear_ctr),
    // Outputs
    .if_id_reg(if_id_reg)
  );

IDU u_IDU(
    .clk                               (clk                       ),
    .rst                               (rst                       ),
    .if_id_reg                         (if_id_reg                 ),
    .wb_reg_wen                        (reg_wen                   ),
    .wb_reg_waddr                      (reg_waddr                 ),
    .wb_reg_wdata                      (reg_wdata                 ),
    // Outputs
    .PC                                (id_exe_PC                 ),
    .Instr                             (id_exe_Instr              ),
    .PC_4                              (id_exe_PC_4               ),
    .reg_wen                           (id_exe_reg_wen            ),
    .reg_wb_sel                        (id_exe_reg_wb_sel         ),
    .aluasrc                           (id_exe_aluasrc            ),
    .alubsrc                           (id_exe_alubsrc            ),
    .alu_op                            (id_exe_alu_op             ),
    .do_branch                         (id_exe_do_branch          ),
    .do_jump                           (id_exe_do_jump            ),
    .branch_cond                       (id_exe_branch_cond        ),
    .mem_op                            (id_exe_mem_op             ),
    .mem_wen                           (id_exe_mem_wen            ),
    .mem_ren                           (id_exe_mem_ren            ),
    .Imm                               (id_exe_Imm                ),
    .raddr1                            (id_exe_raddr1             ),
    .raddr2                            (id_exe_raddr2             ),
    .reg_waddr                         (id_exe_reg_waddr          ),
    .rdata1                            (id_exe_rdata1             ),
    .rdata2                            (id_exe_rdata2             ) 
);


ID_EXE_REG  ID_EXE_REG_inst (
    .clk                               (clk                       ),
    .rst                               (rst                       ),
    .PC                                (id_exe_PC                 ),
    .Instr                             (id_exe_Instr              ),
    .PC_4                              (id_exe_PC_4               ),
    .reg_wen                           (id_exe_reg_wen            ),
    .reg_wb_sel                        (id_exe_reg_wb_sel         ),
    .aluasrc                           (id_exe_aluasrc            ),
    .alubsrc                           (id_exe_alubsrc            ),
    .alu_op                            (id_exe_alu_op             ),
    .do_branch                         (id_exe_do_branch          ),
    .do_jump                           (id_exe_do_jump            ),
    .branch_cond                       (id_exe_branch_cond        ),
    .mem_op                            (id_exe_mem_op             ),
    .mem_wen                           (id_exe_mem_wen            ),
    .mem_ren                           (id_exe_mem_ren            ),
    .imm                               (id_exe_Imm                ),
    .raddr1                            (id_exe_raddr1             ),
    .raddr2                            (id_exe_raddr2             ),
    .reg_waddr                         (id_exe_reg_waddr          ),
    .rdata1                            (id_exe_rdata1             ),
    .rdata2                            (id_exe_rdata2             ),
    .hazard_clear_ctr                  (hazard_clear_ctr          ),
    .bpu_clear_ctrl                    (bpu_clear_ctr            ),
    // Outputs
    .id_exe_reg                        (id_exe_reg                ) 
  );

EXU u_EXU(
    .id_exe_reg                        (id_exe_reg                ),
    .forwardingA                       (forwardingA               ),
    .forwardingB                       (forwardingB               ),
    .exe_mem_reg_alu_out               (exe_mem_reg.alu_out       ),
    .mem_wb_reg_wdata                  (reg_wdata                 ),
    // Outputs
    .branch_taken                      (branch_taken              ),
    .PC                                (exe_mem_PC                ),
    .Instr                             (exe_mem_Instr             ),
    .PC_4                              (exe_mem_PC_4              ),
    .reg_wen                           (exe_mem_reg_wen           ),
    .reg_wb_sel                        (exe_mem_reg_wb_sel        ),
    .mem_op                            (exe_mem_mem_op            ),
    .mem_wen                           (exe_mem_mem_wen           ),
    .mem_ren                           (exe_mem_mem_ren           ),
    .reg_waddr                         (exe_mem_reg_waddr         ),
    .alu_out                           (exe_mem_alu_out           ),
    .rs2                               (exe_mem_rs2               ) 
);

EXE_MEM_REG  EXE_MEM_REG_inst (
    .clk                               (clk                       ),
    .rst                               (rst                       ),
    .PC                                (exe_mem_PC                ),
    .Instr                             (exe_mem_Instr             ),
    .PC_4                              (exe_mem_PC_4              ),
    .reg_wen                           (exe_mem_reg_wen           ),
    .reg_wb_sel                        (exe_mem_reg_wb_sel        ),
    .mem_op                            (exe_mem_mem_op            ),
    .mem_wen                           (exe_mem_mem_wen           ),
    .mem_ren                           (exe_mem_mem_ren           ),
    .reg_waddr                         (exe_mem_reg_waddr         ),
    .alu_out                           (exe_mem_alu_out           ),
    .rs2                               (exe_mem_rs2               ),
    .bpu_clear_ctrl                    (bpu_clear_ctr            ),
    // Outputs
    .exe_mem_reg                       (exe_mem_reg               ) 
  );

MEMU u_MEMU(
    .clk                               (clk                       ),
    .rst                               (rst                       ),
    .exe_mem_reg                       (exe_mem_reg               ),
    // Outputs
    .PC                                (mem_wb_PC                 ),
    .Instr                             (mem_wb_Instr              ),
    .PC_4                              (mem_wb_PC_4               ),
    .reg_wen                           (mem_wb_reg_wen            ),
    .reg_wb_sel                        (mem_wb_reg_wb_sel         ),
    .reg_waddr                         (mem_wb_reg_waddr          ),
    .alu_out                           (mem_wb_alu_out            ),
    .mem_out                           (mem_wb_mem_out            ) 
);

MEM_WB_REG  MEM_WB_REG_inst (
    .clk                               (clk                       ),
    .rst                               (rst                       ),
    .PC                                (mem_wb_PC                 ),
    .Instr                             (mem_wb_Instr              ),
    .PC_4                              (mem_wb_PC_4               ),
    .reg_wen                           (mem_wb_reg_wen            ),
    .reg_wb_sel                        (mem_wb_reg_wb_sel         ),
    .reg_waddr                         (mem_wb_reg_waddr          ),
    .alu_out                           (mem_wb_alu_out            ),
    .mem_out                           (mem_wb_mem_out            ),
    // Outputs
    .mem_wb_reg                        (mem_wb_reg                ) 
  );

WBU u_WBU(
    .mem_wb_reg                        (mem_wb_reg                ),
    // Outputs
    .reg_wen                           (reg_wen                   ),
    .reg_waddr                         (reg_waddr                 ),
    .reg_wdata                         (reg_wdata                 )
);

ForwardingUnit u_ForwardingUnit(
    .id_exe_reg_rs1                    (id_exe_reg.rs1            ),
    .id_exe_reg_rs2                    (id_exe_reg.rs2            ),
    .exe_mem_reg_waddr                 (exe_mem_reg.waddr         ),
    .mem_wb_reg_waddr                  (mem_wb_reg.waddr          ),
    .exe_mem_reg_wen                   (exe_mem_reg.wen           ),
    .mem_wb_reg_wen                    (mem_wb_reg.wen            ),
    // Outputs
    .forwardingA                       (forwardingA               ),
    .forwardingB                       (forwardingB               ) 
);

HazardDetectionUnit u_HazardDetectionUnit(
    .id_exe_reg_mem_ren                (id_exe_reg.mem_ren        ),
    .id_exe_reg_waddr                  (id_exe_reg.reg_waddr      ),
    .if_id_reg_rs1                     (if_id_reg.rs1             ),
    .if_id_reg_rs2                     (if_id_reg.rs2             ),
    // Outputs
    .PC_enable                         (PC_enable                 ),
    .if_id_reg_enable                  (if_id_reg_enable          ),
    .hazard_clear_ctr                  (hazard_clear_ctr          ) 
);

BPU u_BPU(
    .branch_taken  (branch_taken  ),
    // Outputs
    .bpu_clear_ctr (bpu_clear_ctr )
);




    
endmodule