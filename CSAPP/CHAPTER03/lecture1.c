#include <stdio.h>
/**
 * rdx = 5000 rax = 67 rdi = 16
 * mov %rax,22(%rdx,%rdi,2) -> 5000+16*2+22=5054
 *
 * 内存结构
 * 操作系统
 * Code
 * Data:全局变量
 * Heap:动态分配内存->向下生长
 * stack:局部变量,参数->向上生长
 * 内存编号从上往下 0,1,2,, 意思就是栈的内存序列是从大到下 生长
 *
 * 任何指令生成32位值会把寄存器的高32位设置为0
 *
 * !! 特别注意:lea指令不访问内存,只计算
 * lea 6(%rbx,%rdi,8), %rax ->rax = %rbx + 8 * %rdi + 6
 *
 * 每一个算术和逻辑运算符除了lea指令都在隐式的更新状态码
 */
long plus(long x, long y);
void sumStore(long x, long y, long *dest)
{
    long t = plus(x, y);
    *dest = t;
}
int main()
{

    int x = 27;
    x += (~x) + 15;
    printf("x:%d\n", x);
    x = 27;
    x += (~x + 1) + 14;
    printf("x:%d\n", x);
    x = 27;
    x += -x + 14;
    printf("x:%d\n", x); // 都等于14

    return 0;
}