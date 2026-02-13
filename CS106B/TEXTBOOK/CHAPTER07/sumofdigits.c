/**
 * 递归的写法
 */
#include <stdio.h>
int sumOfDigits(int);
int main()
{
    int digit = 1235;
    printf("sumof%d is equal to %d.\n", digit, sumOfDigits(digit)); // 11
    return 0;
}

int sumOfDigits(int digit)
{
    if (digit < 10)
    {
        return digit;
    }
    return sumOfDigits(digit / 10) + digit % 10;
}