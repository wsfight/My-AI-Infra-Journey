#include <iostream>
using namespace std;
int factorials(int n);
int main()
{
    int n = 5;
    cout << factorials(n) << endl;
    return 0;
}
int factorials(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorials(n - 1);
    /*
        3-> 3 * fac(2) -> 3 * 2 * fac(1) -> 3 * 2 * 1 -> 6

    */
}