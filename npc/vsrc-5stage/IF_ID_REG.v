`include "define.vh"
`include "define_pipelineregs.vh"

module IF_ID_REG (
    input wire clk,
    input wire rst,
    input wire [`DATA_WIDTH-1:0] PC,
    input wire [`DATA_WIDTH-1:0] Instr,
    output type_if_id_reg  if_id_reg
);

wire enable = 1;

always @(posedge clk ) begin
    if (rst) begin
        if_id_reg.PC <= PC;
        if_id_reg.Instr <= Instr;
    end
    else if (enable) begin
        // 分别赋值结构体的成员变量给 if_id_reg 的对应成员变量
        if_id_reg.PC <= PC;
        if_id_reg.Instr <= Instr;
    end
    else begin

    end
end

endmodule