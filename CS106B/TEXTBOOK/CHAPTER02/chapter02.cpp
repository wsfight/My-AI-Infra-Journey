/**
 * 函数调用机制:
 *      1.主调函数对传入的实参合法性进行验证
 *      2.系统为新的函数的所需的所有局部变量开辟新的空间:栈帧(stack frame)
 *      3.将实参复制到形参中
 *      4.执行语句,直到遇到return语句.将返回值回给主调函数
 *      5.函数调用的栈帧被删除,所有局部变量被清楚
 * 函数引用可以常用来带出多个返回值
 */

#include <iostream>
#include <cmath>
#include "direction.h"
#include "random.h"
using namespace std;
/* 函数原型*/
int gcd(int x, int y);
int combinations(int n, int k);
int fac(int n);
void getCoefficients(double &a, double &b, double &c);
void solveQuadratic(double a, double b, double c, double &x1, double &x2);
void printRoots(double x1, double x2);
void error(string msg);
int main()
{
    cout << gcd(49, 35) << endl;        // 7
    cout << gcd(32, 33) << endl;        // 1
    cout << combinations(6, 2) << endl; // 15
    double a, b, c, r1, r2;
    getCoefficients(a, b, c);
    solveQuadratic(a, b, c, r1, r2);
    printRoots(r1, r2);
    Direction dir = Direction(0);
    dir = rightFrom(dir); // East
    cout << directionToString(dir) << endl;
    return 0;
}
int gcd(int x, int y)
{
    /**
     * 求x,y的最大公约数
     * 1.对x % y 取余数r,如果余数r为0,则y就为gcd
     * 2.令x=y,y=r.重复第一步.
     * 3.最终的结果就为y.
     */
    int reminder = x % y;
    while (reminder != 0)
    {
        x = y;
        y = reminder;
        reminder = x % y;
    }
    return y;
}
int combinations(int n, int k)
{
    /**
     *  求组合数C(n,k)
     */
    return fac(n) / (fac(k) * fac(n - k));
}
int fac(int n)
{
    /**
     * 求n的阶乘
     */
    if (n == 0 || n == 1)
        return 1;
    return n * fac(n - 1);
}
void getCoefficients(double &a, double &b, double &c)
{
    // 获取二次方程的相关系数
    cout << "请输入二次方程的系数:" << endl;
    cout << "a:";
    cin >> a;
    cout << "b:";
    cin >> b;
    cout << "c:";
    cin >> c;
}
void solveQuadratic(double a, double b, double c, double &x1, double &x2)
{
    // 计算二次方程的根
    if (a == 0)
        error("a的相关系数必须为非0.");
    double distance = b * b - 4 * a * c;
    if (distance < 0)
        error("该二次方程没有实根.");
    double sqrtDistance = sqrt(distance);
    x1 = (-b + sqrtDistance) / (2 * a);
    x2 = (-b - sqrtDistance) / (2 * a);
}
void printRoots(double x1, double x2)
{
    // 打印二次方根的跟
    if (x1 == x2)
    {
        cout << "二次方程拥有相同的跟:" << x1 << endl;
        return;
    }
    cout << "x1:" << x1 << endl;
    cout << "x2:" << x2 << endl;
    return;
}
void error(string msg)
{
    // 显示错误
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}