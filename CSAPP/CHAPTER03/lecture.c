#include <stdio.h>
/**
 * %rip:程序计数器/指令指针  永远指向下一条指令
 * %rbp:%rsp:栈指针
 * %rax:返回值
 * %rdi:第一个参数
 * %rsi:第二个参数
 * %rdx:第三个参数
 *
 * 设置状态指令(具体原理还没有搞清楚)
 * cmp a,b -> 计算b-a 依据计算结果来设置状态码  注意:这个计算并不改变b
 *      - if(a < b)时
 * test a,b -> 计算b&a 依据结果来设置状态码SF和ZF  注意:这个计算并不改变b
 *      - test %rax,%rax 来比较%rax与0
 *      - test %rax %rbx 来比较他们中的任意一bit是否相同
 *
 * 条件码
 * CF:进位标志 -> 用来检查无符号操作的溢出
 * SF:符号标志 -> 用来检查计算结果是否是负数
 * ZF:零标志   -> 用来检查计算结果是否为0
 * OF:溢出标志 -> 用来检查最近的计算结果是否导致一个补码溢出 : 正溢出或者负溢出
 * 用 t = a + b来表示
 * CF: (unsigned)t < (unsigned)a 表明无符号数溢出了
 * SF: t < 0 表明计算结果小于0了
 * ZF: t == 0 表明计算结果等于0了
 * OF: (a<0 == b<0) && (t<0 != a<0) 表明a与b同号 同时 t与a不同号 则有符号数溢出了
 *
 * jump指令(依据条件吗来使用)
 *
 * set指令(依据条件吗来使用)
 * - 设置目的地寄存器的最低一个字节为0或者1 依据条件吗
 * - 不改变其他7个字节
 *
 * movXYZ 指令-转向更大的位宽指令
 * X:{s,z}  - s:符号位扩展 - z:零扩展
 * Y:原来的位宽
 * Z:目的地的位宽
 * movzbl: 原来为1个bytes位宽扩展到4个字节位宽 以0来扩展
 */
int main()
{

    int x = 5;  // mov $5 %rax
    int y = 10; // mov %10 %rcx
    x = y;      // mov %rcx %rax
    int *p = (int *)malloc(sizeof(int));
    x = *p; // mov (%rsi) %rax
    /**
     * 不能 内存->内存
     * 必须 内存->寄存器  然后 寄存器->内存
     */
    int temp = 4; // mov $0x4 %r8       立即数->寄存器
    *p = -127;    // mov %-147 (%rsi)   立即数->内存
    x = y;        // mov %rcx %rax      寄存器->寄存器
    *p = x;       // mov %rax (%rsi)    寄存器->内存
    x = *p;       // mov (%rsi) %rax    内存->寄存器

    x = (x + y);  // addq %rcx %rax
    x = (x * 2);  // salq $1 %rax
    x = (x >> 1); // sarq $1 %rax
    x += 1;       // incq %rax
    y -= 1;       // decq %rax
    x = (-x);     // negq %rax
    x = (~x);     // notq %rax

    // leaq src dest
}
void whatAmI(long *a, long *b)
{
    /**
     *  movq (%rdi), %rax
        movq (%rsi), %rdx
        movq %rdx, (%rdi)
        movq %rax, (%rsi)
        ret

        long *a -> %rdi 第一个参数
        long *b -> %rsi 第二个参数
     */
    long temp = *a;
    long temp1 = *b;
    *a = temp1;
    *b = temp;
}
long m12(long x)
{
    /**
     * leaq (%rdi,rdi,2) %rax    x = x + 2 * x   加载有效地址 往往只计算地址 不去内存进行取值
     * salq 4,%rax               x  = x *16
     */
    return x * 48;
}
long m13(long a, long b, long c)
{
    /**
     *  arith:
        leaq (%rdi,%rsi), %rax
        addq %rdx, %rax
        leaq (%rsi,%rsi,2), %rdx
        salq $4, %rdx
        leaq 4(%rdi,%rdx), %rcx
        imulq %rcx, %rax
        ret
     */
    long ans = a + b;
    ans = ans + c;
    c = b * 48;
    long temp2 = a + c + 4;
    ans = temp2 * ans;
    return ans;
}
int gt(long x, long y)
{
    /**
     * cmp %rsi,%rdi
     * setg %al
     * movzbl %al,%rax
     */
    return x > y;
}