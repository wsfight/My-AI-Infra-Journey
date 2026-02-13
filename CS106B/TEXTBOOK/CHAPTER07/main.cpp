#include <iostream>
#include "myhead.h"
using namespace std;

int main()
{
    string str = "level";
    if (isPalinedrome(str))
    {
        cout << str << "是回文数" << endl;
    }
    else
    {
        cout << str << "不是回文数" << endl;
    }
    return 0;
}