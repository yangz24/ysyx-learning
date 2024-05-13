`include "define.vh"
`include "define_pipelineregs.vh"

module CPU (
    input  wire                         clk                        ,
    input  wire                         rst                        ,

    // for difftest
    output wire                         diff_enable                ,
    output wire        [`PC_WIDTH-1:0]  diff_PC                    ,
    output wire        [`INSTR_WIDTH-1:0]diff_Instr                 ,
    output wire        [`PC_WIDTH-1:0]  nextPC                      
);

/******************************************** IFU  ********************************************/
wire if_id_valid;
wire id_if_ready;
wire [`IF_ID_BUS_WIDTH-1:0] if_id_bus;

/******************************************** IDU  ********************************************/
wire [`REG_ADDR_WIDTH-1:0] if_id_reg_raddr1;
wire [`REG_ADDR_WIDTH-1:0] if_id_reg_raddr2;
wire id_exe_valid;
wire exe_id_ready;
wire [`ID_EXE_BUS_WIDTH-1:0] id_exe_bus;

/******************************************** EXU  ********************************************/
wire branch_taken;
wire [`PC_WIDTH-1:0] branch_PC;
wire [`REG_ADDR_WIDTH-1:0] id_exe_reg_raddr1;
wire [`REG_ADDR_WIDTH-1:0] id_exe_reg_raddr2;
wire id_exe_reg_mem_ren;
wire [`REG_ADDR_WIDTH-1:0] id_exe_reg_waddr;
wire [`PC_WIDTH-1:0] id_exe_reg_PC;
wire exe_mem_valid;
wire mem_exe_ready;
wire [`EXE_MEM_BUS_WIDTH-1:0] exe_mem_bus;

/******************************************** MEMU  ********************************************/
wire [`DATA_WIDTH-1:0] exe_mem_reg_alu_out;
wire [`REG_ADDR_WIDTH-1:0] exe_mem_reg_waddr;
wire exe_mem_reg_wen;
wire mem_wb_valid;
wire wb_mem_ready;
wire [`MEM_WB_BUS_WIDTH-1:0] mem_wb_bus;
wire [`PC_WIDTH-1:0] exe_mem_PC;

/******************************************** WBU  **********/
wire [`REG_ADDR_WIDTH-1:0] mem_wb_reg_waddr;
wire mem_wb_reg_wen;
wire wb_reg_wen;
wire [`REG_ADDR_WIDTH-1:0] wb_reg_waddr;
wire [`DATA_WIDTH-1:0] wb_reg_wdata;
// for difftest
wire [`PC_WIDTH-1:0] PC;
wire [`INSTR_WIDTH-1:0] Instr;
// wire diffen;
wire wb__valid;
wire wb_branch_taken;

/******************************************** FORWARDING UNIT output ********************************************/
wire [`FORWARDING_A_LENGTH-1:0] forwardingA;
wire [`FORWARDING_B_LENGTH-1:0] forwardingB;

/******************************************** Hazard Detection Unit output **********/
wire hazard_detected;
// wire PC_enable;
// wire if_id_reg_enable;
// wire hazard_clear_ctrl;

/******************************************** BPU output **********/
wire bpu_clear_ctrl;

/******************************************** modules instantiation ********************************************/
IFU u_IFU(
    .clk                               (clk                       ),
    .rst                               (rst                       ),
    .branch_taken                      (branch_taken              ),
    .branch_PC                         (branch_PC                 ),
    // .PC_enable                         (PC_enable                 ),
    .hazard_detected                   (hazard_detected           ),
    .bpu_clear_ctrl                    (bpu_clear_ctrl            ),
    .m_valid                           (if_id_valid               ),
    .m_ready                           (id_if_ready               ),
    .if_id_bus                         (if_id_bus                 ) 
);

IDU u_IDU(
    .clk                               (clk                       ),
    .rst                               (rst                       ),
    .if_id_bus                         (if_id_bus                 ),
    // .if_id_reg_enable (if_id_reg_enable ),
    .hazard_detected                   (hazard_detected           ),
    .s_valid                           (if_id_valid               ),
    .s_ready                           (id_if_ready               ),
    .m_valid                           (id_exe_valid              ),
    .m_ready                           (exe_id_ready               ),
    .bpu_clear_ctrl                    (bpu_clear_ctrl            ),
    .wb_reg_wen                        (wb_reg_wen                ),
    .wb_reg_waddr                      (wb_reg_waddr              ),
    .wb_reg_wdata                      (wb_reg_wdata              ),
    .if_id_reg_raddr1                  (if_id_reg_raddr1          ),
    .if_id_reg_raddr2                  (if_id_reg_raddr2          ),
    .id_exe_bus                        (id_exe_bus                ) 
);

EXU u_EXU(
    .clk                               (clk                       ),
    .rst                               (rst                       ),
    .id_exe_bus                        (id_exe_bus                ),
    // .hazard_clear_ctrl                 (hazard_clear_ctrl         ),
    .bpu_clear_ctrl                    (bpu_clear_ctrl            ),
    .forwardingA                       (forwardingA               ),
    .forwardingB                       (forwardingB               ),
    .exe_mem_reg_alu_out               (exe_mem_reg_alu_out       ),
    .wb_reg_wdata                      (wb_reg_wdata              ),
    .branch_taken                      (branch_taken              ),
    .branch_PC                         (branch_PC                 ),
    .id_exe_reg_raddr1                 (id_exe_reg_raddr1         ),
    .id_exe_reg_raddr2                 (id_exe_reg_raddr2         ),
    .id_exe_reg_mem_ren                (id_exe_reg_mem_ren        ),
    .id_exe_reg_waddr                  (id_exe_reg_waddr          ),
    .id_exe_reg_PC                     (id_exe_reg_PC             ),
    .s_valid                           (id_exe_valid              ),
    .s_ready                           (exe_id_ready              ),
    .m_valid                           (exe_mem_valid             ),
    .m_ready                           (mem_exe_ready             ),
    .exe_mem_bus                       (exe_mem_bus               ) 
);

MEMU u_MEMU(
    .clk                               (clk                       ),
    .rst                               (rst                       ),
    .exe_mem_bus                       (exe_mem_bus               ),
    // .bpu_clear_ctrl                    (bpu_clear_ctrl            ),
    .exe_mem_reg_alu_out               (exe_mem_reg_alu_out       ),
    .exe_mem_reg_waddr                 (exe_mem_reg_waddr         ),
    .exe_mem_reg_wen                   (exe_mem_reg_wen           ),
    .exe_mem_PC                        (exe_mem_PC             ),
    .s_valid                           (exe_mem_valid             ),
    .s_ready                           (mem_exe_ready             ),
    .m_valid                           (mem_wb_valid              ),
    .m_ready                           (wb_mem_ready              ),
    .mem_wb_bus                        (mem_wb_bus                ) 
);

WBU u_WBU(
    .clk                               (clk                       ),
    .rst                               (rst                       ),
    .mem_wb_bus                        (mem_wb_bus                ),
    .mem_wb_reg_waddr                  (mem_wb_reg_waddr          ),
    .mem_wb_reg_wen                    (mem_wb_reg_wen            ),
    .wb_reg_wen                        (wb_reg_wen                ),
    .wb_reg_waddr                      (wb_reg_waddr              ),
    .wb_reg_wdata                      (wb_reg_wdata              ),
    .PC                                (PC                        ),
    .Instr                             (Instr                     ),
    // .diffen                            (diffen                    ),
    .wb_branch_taken                   (wb_branch_taken           ),
    .s_valid                           (mem_wb_valid              ),
    .s_ready                           (wb_mem_ready              ),
    .m_valid                           (wb__valid                 ) 
);

ForwardingUnit u_ForwardingUnit(
    .id_exe_reg_raddr1    (id_exe_reg_raddr1   ),
    .id_exe_reg_raddr2    (id_exe_reg_raddr2   ),
    .exe_mem_reg_waddr (exe_mem_reg_waddr ),
    .mem_wb_reg_waddr  (mem_wb_reg_waddr  ),
    .exe_mem_reg_wen   (exe_mem_reg_wen   ),
    .mem_wb_reg_wen    (mem_wb_reg_wen    ),
    .forwardingA       (forwardingA       ),
    .forwardingB       (forwardingB       )
);

HazardDetectionUnit u_HazardDetectionUnit(
    .id_exe_reg_mem_ren (id_exe_reg_mem_ren ),
    .id_exe_reg_waddr   (id_exe_reg_waddr   ),
    .if_id_reg_raddr1      (if_id_reg_raddr1      ),
    .if_id_reg_raddr2      (if_id_reg_raddr2      ),
    .hazard_detected       (hazard_detected       )
    // .PC_enable          (PC_enable          ),
    // .if_id_reg_enable   (if_id_reg_enable   ),
    // .hazard_clear_ctrl  (hazard_clear_ctrl  )
);

BPU u_BPU(
    .clk            (clk            ),
    .rst            (rst            ),
    .branch_taken   (branch_taken   ),
    .bpu_clear_ctrl (bpu_clear_ctrl )
);

Difftest u_Difftest(
    .clk                               (clk                       ),
    .rst                               (rst                       ),
    .diffen                            (wb__valid                 ),
    .PC                                (PC                        ),
    .Instr                             (Instr                     ),
    .branch_taken                      (wb_branch_taken           ),
    .branch_PC                         (id_exe_reg_PC             ),
    .hazard_detected                   (hazard_detected           ),
    .exe_mem_PC                        (exe_mem_PC             ),
    .diff_enable                       (diff_enable               ),
    .diff_PC                           (diff_PC                   ),
    .diff_Instr                        (diff_Instr                ),
    .nextPC                            (nextPC                    ) 
);



endmodule