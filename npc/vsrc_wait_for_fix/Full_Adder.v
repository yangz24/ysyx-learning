module Full_Adder (
    input A, // 输入 A
    input B, // 输入 B
    input Cin, // 进位输入
    output Sum, // 输出和
    output Cout // 输出进位
);

    assign {Cout, Sum} = A + B + Cin; // 使用系统函数直接实现全加器功能

endmodule
