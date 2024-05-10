`include "define.v"

module CPU (
    input  wire                         clk                        ,
    input  wire                         rst                        ,
    output wire                         diffen                     ,
    output wire        [`DATA_WIDTH-1:0]diffPC                     ,
    output wire        [`DATA_WIDTH-1:0]diffInstr                  ,
    output wire        [`DATA_WIDTH-1:0]nextPC                      
);

wire                                    PCsrc                      ;
wire                   [`DATA_WIDTH-1:0]BranchPC                   ;
wire                   [`DATA_WIDTH-1:0]IDReg_PC                   ;
wire                   [`DATA_WIDTH-1:0]IDReg_Instr                ;
wire                                    PCwrite                    ;
wire                                    if_id_write                ;
wire                   [   6:0]         IDReg_op                   ;
wire                   [   4:0]         IDReg_rs1                  ;
wire                   [   4:0]         IDReg_rs2                  ;
wire                   [   4:0]         IDReg_Regrd                ;
wire                   [   2:0]         IDReg_Func3                ;
wire                   [   6:0]         IDReg_Func7                ;
wire [11:0] IDReg_csr;
wire                                    HoldOnRegWr                ;
wire                   [`ADDR_WIDTH-1:0]Rw                         ;
wire                   [`DATA_WIDTH-1:0]busW                       ;
wire                                    ForwardingA                ;
wire                                    ForwardingB                ;
wire                                    ClearCtr                   ;
wire                                    EXReg_MemRd                ;
wire                   [`ADDR_WIDTH-1:0]EXReg_Regrs1               ;
wire                   [`ADDR_WIDTH-1:0]EXReg_Regrs2               ;
wire                                    EXReg_ALUAsrc              ;
wire                   [   1:0]         EXReg_ALUBsrc              ;
wire                   [   3:0]         EXReg_ALUctr               ;
wire                   [   2:0]         EXReg_Branch               ;
wire                                    EXReg_RegWr                ;
wire                                    EXReg_MemtoReg             ;
wire                                    EXReg_MemWr                ;
wire                   [   2:0]         EXReg_MemOp                ;
wire                   [`DATA_WIDTH-1:0]EXReg_busA                 ;
wire                   [`DATA_WIDTH-1:0]EXReg_busB                 ;
wire                   [`ADDR_WIDTH-1:0]EXReg_Regrd                ;
wire                   [`DATA_WIDTH-1:0]EXReg_Imm                  ;
wire                   [`DATA_WIDTH-1:0]EXReg_PC                   ;
wire                   [`DATA_WIDTH-1:0]EXReg_Instr                ;
wire                                    WBReg_RegWr                ;
wire                                    WBReg_MemtoReg             ;
wire                   [`ADDR_WIDTH-1:0]WBReg_Regrd                ;
wire                   [`DATA_WIDTH-1:0]WBReg_ALUout               ;
wire                   [`DATA_WIDTH-1:0]WBReg_DataOut              ;
wire                   [`DATA_WIDTH-1:0]BranchPC                   ;
wire                   [`DATA_WIDTH-1:0]WBReg_PC                   ;
wire                   [`DATA_WIDTH-1:0]WBReg_Instr                ;

wire                                    BPUClearCtr                ;

wire                   [`DATA_WIDTH-1:0]HoldPC                     ;
wire                   [`DATA_WIDTH-1:0]HoldInstr                  ;

wire                                    if_diffen                  ;
wire                                    id_diffen                  ;
wire                                    ex_diffen                  ;
wire                                    wb_diffen                  ;

wire                                    WBReg_PCsrc, HoldPCsrc     ;

wire                   [  11:0]         IDReg_csr                  ;
wire                   [`DATA_WIDTH-1:0]CSRin                      ;
wire                                    CSRWren                    ;
wire                                    ecallen                    ;
wire                   [  63:0]         ecall_packageen            ;
wire                                    mreten                     ;
wire                   [`DATA_WIDTH-1:0]EXReg_CSRout               ;
wire                                    EXReg_CSRRegvalid          ;
wire                                    EXReg_CSRRegWr             ;
wire                                    EXReg_CSRset               ;
wire                                    EXReg_ecall                ;
wire                   [  63:0]         EXReg_ecall_package        ;
wire                                    EXReg_mret                 ;
wire [11:0] Reg_csren;
wire [11:0] EXReg_csr;
wire [11:0] WBReg_csr ;

wire [`DATA_WIDTH-1:0] WBReg_CSRout       ; 
wire  WBReg_CSRRegvalid  ; 
wire  WBReg_CSRRegWr     ; 
wire  WBReg_CSRset       ; 
wire  WBReg_ecall        ; 
wire [63:0] WBReg_ecall_package; 
wire  WBReg_mret         ; 
wire [`DATA_WIDTH-1:0] WBReg_ALUa         ; 


IFU u_IFU(
    .clk                               (clk                       ),
    .rst                               (rst                       ),
  // .PCwrite     (PCwrite     ),
  // .if_id_write (if_id_write ),
    .PCsrc                             (PCsrc                     ),
    .BranchPC                          (BranchPC                  ),
    .IDReg_PC                          (IDReg_PC                  ),
    .IDReg_Instr                       (IDReg_Instr               ),
    .IDReg_op                          (IDReg_op                  ),
    .IDReg_rs1                         (IDReg_rs1                 ),
    .IDReg_rs2                         (IDReg_rs2                 ),
    .IDReg_Regrd                       (IDReg_Regrd               ),
    .IDReg_Func3                       (IDReg_Func3               ),
    .IDReg_Func7                       (IDReg_Func7               ),
    .if_diffen                         (if_diffen                 ),
    .BPUClearCtr                       (BPUClearCtr               ),
    .IDReg_csr                         (IDReg_csr                 ) 
);


IDU u_IDU(
    .Reg_csren          (Reg_csren),
    .EXReg_csr           (EXReg_csr),
    .EXReg_CSRRegWr                    (EXReg_CSRRegWr            ),
    .EXReg_CSRset                      (EXReg_CSRset              ),
    .EXReg_ecall                       (EXReg_ecall               ),
    .EXReg_ecall_package               (EXReg_ecall_package       ),
    .EXReg_mret                        (EXReg_mret                ),
    .IDReg_csr                         (IDReg_csr                 ),
    .CSRin                             (CSRin                     ),
    .CSRWren                           (CSRWren                   ),
    .ecallen                           (ecallen                   ),
    .ecall_packageen                   (ecall_packageen           ),
    // .mreten                            (mreten                    ),
    .EXReg_CSRout                      (EXReg_CSRout              ),
    .EXReg_CSRRegvalid                 (EXReg_CSRRegvalid         ),
    .clk                               (clk                       ),
    .rst                               (rst                       ),
    .IDReg_PC                          (IDReg_PC                  ),
    .IDReg_Instr                       (IDReg_Instr               ),
    .IDReg_op                          (IDReg_op                  ),
    .IDReg_rs1                         (IDReg_rs1                 ),
    .IDReg_rs2                         (IDReg_rs2                 ),
    .IDReg_Regrd                       (IDReg_Regrd               ),
    .IDReg_Func3                       (IDReg_Func3               ),
    .IDReg_Func7                       (IDReg_Func7               ),
    .HoldOnRegWr                       (HoldOnRegWr               ),
    .Rw                                (Rw                        ),
    .busW                              (busW                      ),
  // .ClearCtr       (ClearCtr       ),
    .EXReg_ALUAsrc                     (EXReg_ALUAsrc             ),
    .EXReg_ALUBsrc                     (EXReg_ALUBsrc             ),
    .EXReg_ALUctr                      (EXReg_ALUctr              ),
    .EXReg_Branch                      (EXReg_Branch              ),
    .EXReg_RegWr                       (EXReg_RegWr               ),
    .EXReg_MemtoReg                    (EXReg_MemtoReg            ),
    .EXReg_MemWr                       (EXReg_MemWr               ),
    .EXReg_MemRd                       (EXReg_MemRd               ),
    .EXReg_MemOp                       (EXReg_MemOp               ),
    .EXReg_busA                        (EXReg_busA                ),
    .EXReg_busB                        (EXReg_busB                ),
    .EXReg_Regrd                       (EXReg_Regrd               ),
    .EXReg_Regrs1                      (EXReg_Regrs1              ),
    .EXReg_Regrs2                      (EXReg_Regrs2              ),
    .EXReg_Imm                         (EXReg_Imm                 ),
    .EXReg_PC                          (EXReg_PC                  ),
    .EXReg_Instr                       (EXReg_Instr               ),
    .BPUClearCtr                       (BPUClearCtr               ),
    .if_diffen                         (if_diffen                 ),
    .id_diffen                         (id_diffen                 ) 
);


EXU u_EXU(
    .EXReg_csr              (EXReg_csr),
    .WBReg_csr              (WBReg_csr),
    .WBReg_CSRout           (WBReg_CSRout),
    .WBReg_CSRRegvalid      (WBReg_CSRRegvalid),
    .WBReg_CSRRegWr         (WBReg_CSRRegWr),
    .WBReg_CSRset           (WBReg_CSRset),
    .WBReg_ecall            (WBReg_ecall),
    .WBReg_ecall_package    (WBReg_ecall_package),
    // .WBReg_mret             (WBReg_mret),
    .WBReg_ALUa             (WBReg_ALUa),
    .EXReg_CSRout                      (EXReg_CSRout              ),
    .EXReg_CSRRegvalid                 (EXReg_CSRRegvalid         ),
    .EXReg_CSRRegWr                    (EXReg_CSRRegWr            ),
    .EXReg_CSRset                      (EXReg_CSRset              ),
    .EXReg_ecall                       (EXReg_ecall               ),
    .EXReg_ecall_package               (EXReg_ecall_package       ),
    .EXReg_mret                        (EXReg_mret                ),
    .clk                               (clk                       ),
    .rst                               (rst                       ),
    .EXReg_ALUAsrc                     (EXReg_ALUAsrc             ),
    .EXReg_ALUBsrc                     (EXReg_ALUBsrc             ),
    .EXReg_ALUctr                      (EXReg_ALUctr              ),
    .EXReg_Branch                      (EXReg_Branch              ),
    .EXReg_MemtoReg                    (EXReg_MemtoReg            ),
    .EXReg_MemWr                       (EXReg_MemWr               ),
    .EXReg_MemRd                       (EXReg_MemRd               ),
    .EXReg_MemOp                       (EXReg_MemOp               ),
    .EXReg_RegWr                       (EXReg_RegWr               ),
    .ForwardingA                       (ForwardingA               ),
    .ForwardingB                       (ForwardingB               ),
    .busW                              (busW                      ),
    .EXReg_busA                        (EXReg_busA                ),
    .EXReg_busB                        (EXReg_busB                ),
    .EXReg_Regrd                       (EXReg_Regrd               ),
    .EXReg_Imm                         (EXReg_Imm                 ),
    .EXReg_PC                          (EXReg_PC                  ),
    .EXReg_Instr                       (EXReg_Instr               ),
    .PCsrc                             (PCsrc                     ),
    .WBReg_PCsrc                       (WBReg_PCsrc               ),
    .WBReg_RegWr                       (WBReg_RegWr               ),
    .WBReg_MemtoReg                    (WBReg_MemtoReg            ),
    .WBReg_Regrd                       (WBReg_Regrd               ),
    .WBReg_ALUout                      (WBReg_ALUout              ),
    .WBReg_DataOut                     (WBReg_DataOut             ),
    .BranchPC                          (BranchPC                  ),
    .WBReg_PC                          (WBReg_PC                  ),
    .WBReg_Instr                       (WBReg_Instr               ),
    .id_diffen                         (id_diffen                 ),
    .ex_diffen                         (ex_diffen                 ) 
);

WBU u_WBU(
    .WBReg_csr                  (WBReg_csr),
    .Reg_csren              (Reg_csren),
    .CSRin                             (CSRin                     ),
    .CSRWren                           (CSRWren                   ),
    .ecallen                           (ecallen                   ),
    .ecall_packageen                   (ecall_packageen           ),
    // .mreten                            (mreten                    ),
    .WBReg_CSRout                      (WBReg_CSRout              ),
    .WBReg_CSRRegvalid                 (WBReg_CSRRegvalid         ),
    .WBReg_CSRRegWr                    (WBReg_CSRRegWr            ),
    .WBReg_CSRset                      (WBReg_CSRset              ),
    .WBReg_ecall                       (WBReg_ecall               ),
    .WBReg_ecall_package               (WBReg_ecall_package       ),
    // .WBReg_mret                        (WBReg_mret                ),
    .WBReg_ALUa                        (WBReg_ALUa                ),
    .clk                               (clk                       ),
    .rst                               (rst                       ),
    .WBReg_MemtoReg                    (WBReg_MemtoReg            ),
    .WBReg_RegWr                       (WBReg_RegWr               ),
    .WBReg_Regrd                       (WBReg_Regrd               ),
    .WBReg_ALUout                      (WBReg_ALUout              ),
    .WBReg_DataOut                     (WBReg_DataOut             ),
    .WBReg_PC                          (WBReg_PC                  ),
    .WBReg_Instr                       (WBReg_Instr               ),
    .HoldOnRegWr                       (HoldOnRegWr               ),
    .Rw                                (Rw                        ),
    .busW                              (busW                      ),
    .HoldPC                            (HoldPC                    ),
    .HoldInstr                         (HoldInstr                 ),
    .ex_diffen                         (ex_diffen                 ),
    .wb_diffen                         (wb_diffen                 ),
    .WBReg_PCsrc                       (WBReg_PCsrc               ),
    .HoldPCsrc                         (HoldPCsrc                 ) 
);

ForwardingUnit u_ForwardingUnit(
    .EXReg_Regrs1                      (EXReg_Regrs1              ),
    .EXReg_Regrs2                      (EXReg_Regrs2              ),
    .WBReg_Regrd                       (WBReg_Regrd               ),
    .WBReg_RegWr                       (WBReg_RegWr               ),
    .ForwardingA                       (ForwardingA               ),
    .ForwardingB                       (ForwardingB               ) 
);

// HazardDetectionUnit u_HazardDetectionUnit(
//   .EXReg_MemRd (EXReg_MemRd ),
//   .EXReg_Regrd (EXReg_Regrd ),
//   .IDReg_rs1   (IDReg_rs1   ),
//   .IDReg_rs2   (IDReg_rs2   ),
//   .PCwrite     (PCwrite     ),
//   .if_id_write (if_id_write ),
//   .ClearCtr    (ClearCtr    )
// );

BPU u_BPU(
    .PCsrc                             (PCsrc                     ),
    .BPUClearCtr                       (BPUClearCtr               ) 
);

`ifdef DIFFTEST
Difftest u_Difftest(
    .wb_diffen                         (wb_diffen                 ),
    .PC                                (HoldPC                    ),
    .Instr                             (HoldInstr                 ),
    .diffen                            (diffen                    ),
    .diffPC                            (diffPC                    ),
    .diffInstr                         (diffInstr                 ),
    .IDReg_PC                          (IDReg_PC                  ),
    .WBReg_PC                          (WBReg_PC                  ),
    .HoldPCsrc                         (HoldPCsrc                 ),
    .nextPC                            (nextPC                    ) 
);
`endif



endmodule
