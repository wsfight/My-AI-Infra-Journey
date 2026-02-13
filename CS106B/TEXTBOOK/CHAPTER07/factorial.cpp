#include <iostream>
int fact1(int num);
int main()
{
    int num = 5;
    std::cout << "非递归方式:" << fact1(num) << std::endl; // 120
    return 0;
}
int fact1(int num)
{
    // 运用非递归的方法计算阶乘
    int ans = 1;
    for (int i = num; i > 0; --i)
    {
        ans *= i;
    }
    return ans;
}