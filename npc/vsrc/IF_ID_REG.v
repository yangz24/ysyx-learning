`include "define.vh"
`include "define_pipelineregs.vh"

module IF_ID_REG (
    input wire clk,
    input wire rst,
    input wire [`PC_WIDTH-1:0] PC,
    input wire [`INSTR_WIDTH-1:0] Instr,
    input wire [`PC_WIDTH-1:0] PC_4,

    // enable pipeline register update
    input wire if_id_reg_enable,

    // bpu clear control, when set to 1, clear the IF/ID/EX pipeline
    input wire bpu_clear_ctrl,

    output type_if_id_reg  if_id_reg
);

always @(posedge clk ) begin
    if (rst || bpu_clear_ctrl) begin
        if_id_reg.PC <= 0;
        if_id_reg.Instr <= 0;
        if_id_reg.PC_4 <= 0;
    end
    else if (if_id_reg_enable) begin
        // 分别赋值结构体的成员变量给 if_id_reg 的对应成员变量
        if_id_reg.PC <= PC;
        if_id_reg.Instr <= Instr;
        if_id_reg.PC_4 <= PC_4;
    end
    else begin

    end
end

endmodule