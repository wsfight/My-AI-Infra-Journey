#include <stdio.h>

void multstore(long, long, long *);

int main()
{
    long d;
    multstore(4, 6, &d);
    printf("4 * 6= %ld\n", d);
    return 0;
}
long mult2(long a, long b)
{
    long s = a * b;
    return s;
}