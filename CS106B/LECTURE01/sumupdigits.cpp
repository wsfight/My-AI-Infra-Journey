#include <iostream>
#include <string>
using namespace std;
int getInteger(string s)
{

    int result;
    cout << s << endl;
    cin >> result;
    return result;
}
int sumOfDigitsOf(int n);
int main()
{
    int n = getInteger("Enter an interger:");
    int digitSum = sumOfDigitsOf(n);
    cout << n << " sum to " << digitSum << endl;
    return 0;
}
int sumOfDigitsOf(int n)
{
    int result = 0;
    while (n > 0)
    {
        int remainder = n % 10; // 取当前数的个位数
        n /= 10;
        result += remainder;
    }
    return result;
}