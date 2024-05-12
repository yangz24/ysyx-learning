`include "define.vh"

module ControlGen (
    input wire [`FUNC3_LENGTH-1:0] func3,
    input wire [`FUNC7_LENGTH-1:0] func7,
    input wire [`OPCODE_LENGTH-1:0] opcode,

    // imm generator control
    output wire [`EXTOP_LENGTH-1:0] ExtOp,

    // regfile control
    output wire reg_wen,
    output wire [`REG_WRITE_BACK_SEL_LENGTH-1:0] reg_wb_sel,

    // alu control
    output wire aluasrc,
    output wire alubsrc,
    output reg [`ALU_CTRL_LENGTH-1:0] alu_op,

    // branch control
    output wire do_branch,
    output wire do_jump,
    output wire [`BRANCH_COND_LENGTH-1:0] branch_cond,

    // memory control
    output wire [`MEM_CTRL_LENGTH-1:0] mem_op,
    output wire mem_wen,
    output wire mem_ren
);

    /****************************************** ExtOP ******************************************/
    //operation type for imm generator
    assign ExtOp  = (opcode == `OPCODE_I_INT || opcode == `OPCODE_I_LOAD || opcode == `OPCODE_I_JALR) ? `EXTOP_I :
                    (opcode == `OPCODE_U_LUI || opcode == `OPCODE_U_AUIPC) ? `EXTOP_U :
                    (opcode == `OPCODE_S) ? `EXTOP_S :
                    (opcode == `OPCODE_B) ? `EXTOP_B :
                    (opcode == `OPCODE_J) ? `EXTOP_J : 
                    (opcode == `OPCODE_R) ? `EXTOP_R : `EXTOP_DEFAULT;

    /******************************************** RegFile control *******************************************/ 
    // regfile write enable
    //  only I/U/J/R type instruction will write to regfile
    assign reg_wen = (ExtOp == `EXTOP_I || ExtOp == `EXTOP_U || ExtOp == `EXTOP_J || ExtOp == `EXTOP_R) ? 1 : 0;

    // regfile write back select
    assign reg_wb_sel = (opcode == `OPCODE_I_LOAD) ? `REG_WRITE_BACK_SEL_MEM : 
                        (opcode == `OPCODE_J || opcode == `OPCODE_I_JALR) ? `REG_WRITE_BACK_SEL_PC_4 : 
                        `REG_WRITE_BACK_SEL_ALU;

    /******************************************** ALU control ********************************************/
    // alua source select
    // only auipc/jalr/jal type instruction will use PC as alua source
    assign aluasrc = (opcode == `OPCODE_U_AUIPC ||  opcode == `OPCODE_J || opcode == `OPCODE_B) ? `ALU_ASRC_PC : `ALU_ASRC_RS1;

    // alub source select
    // only R type instruction will use rs2 as alub source
    assign alubsrc = (opcode == `OPCODE_R) ? `ALU_BSRC_RS2 : `ALU_BSRC_IMM; 

    // alu operation select
    always @(*) begin
        if (opcode == `OPCODE_I_LOAD ||
            opcode == `OPCODE_S || 
            opcode == `OPCODE_J || 
            opcode == `OPCODE_I_JALR || 
            opcode == `OPCODE_U_AUIPC ) begin
                alu_op = `ALU_CTRL_ADD; // load/store/jump/jalr/auipc for add
        end
        else if (opcode == `OPCODE_U_LUI) begin
            alu_op = `ALU_CTRL_COPY_B; // lui for copy immediate to rd
        end
        else if (opcode == `OPCODE_I_INT) begin
            case (func3)
                3'b011:  alu_op = 4'b1010; // func3 is 011 for sltiu
                3'b101:  alu_op = {func7[5], 3'b101}; // func7[5] is 1 for srai, 0 for srli
                default: alu_op = {1'b0, func3}; 
            endcase           
        end
        else if (opcode == `OPCODE_R) begin
            case (func3)
                3'b011:  alu_op = 4'b1010; // func3 is 011 for sltu
                3'b101:  alu_op = {func7[5], 3'b101}; // func7[5] is 1 for sra, 0 for srl
                3'b000:  alu_op = {func7[5], 3'b000}; // func7[5] is 1 for sub, 0 for add
                default: alu_op = {1'b0, func3};
            endcase
        end 
        else begin
            alu_op = `ALU_CTRL_DEFAULT; // do add
        end
    end

    /******************************************** Branch control **********/

    // only B type instruction will use branch condition
    assign do_branch = (opcode == `OPCODE_B) ? 1 : 0;

    // jump condition select
    // only J type instruction will use jump condition
    assign do_jump = (opcode == `OPCODE_J || opcode == `OPCODE_I_JALR) ? 1 : 0;

    // branch condition select
    assign branch_cond = (opcode == `OPCODE_B) ? func3 : `BRANCH_COND_DEFAULT;

    /******************************************** Memory control **********/
    // memory operation select
    assign mem_op = (opcode == `OPCODE_I_LOAD || opcode == `OPCODE_S) ? func3 :`MEM_CTRL_LOAD_BYTE;

    // memory write enable
    assign mem_wen = (opcode == `OPCODE_S) ? 1 : 0;

    // memory read enable
    assign mem_ren = (opcode == `OPCODE_I_LOAD) ? 1 : 0;



endmodule