/**
 * 简述一些c++的概念
 * class:
 *      - 由成员组成.成员包括数据或者函数(成员函数)
 *      - 类的实例叫做对象
 */
#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
    int a = 30;
    Vector<int> v1 = {1, 2, 3};
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(a);
    auto it = v1.begin();
    for (; it != v1.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}