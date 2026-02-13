#include <iostream>
#include <string>
using namespace std;
/**
 * 写一个判断回文数的函数
 */
bool isPalinedrome(string str)
{
    int len = str.size();
    if (len <= 1)
        return true;
    else
    {
        return str[0] == str[len - 1] && isPalinedrome(str.substr(1, len - 2));
    }
}