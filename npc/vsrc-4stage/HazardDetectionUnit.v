// `include "define.v"

// module HazardDetectionUnit (
//     input wire EXReg_MemRd,
//     input wire [`ADDR_WIDTH-1:0] EXReg_Regrd,
//     input wire [`ADDR_WIDTH-1:0] IDReg_rs1,
//     input wire [`ADDR_WIDTH-1:0] IDReg_rs2,
//     output reg PCwrite,
//     output reg if_id_write,
//     output reg ClearCtr
// );

// assign PCwrite = (EXReg_MemRd && ((EXReg_Regrd == IDReg_rs1) || (EXReg_Regrd == IDReg_rs2)))? 0 : 1; // 1代表允许PC变化
// assign if_id_write = (EXReg_MemRd && ((EXReg_Regrd == IDReg_rs1) || (EXReg_Regrd == IDReg_rs2)))? 0 : 1; // 1代表允许if_id流水线寄存器变化
// assign ClearCtr = (EXReg_MemRd && ((EXReg_Regrd == IDReg_rs1) || (EXReg_Regrd == IDReg_rs2)))? 1 : 0; // 1 代表清0控制信号

// endmodule