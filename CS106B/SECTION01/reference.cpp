#include <iostream>
#include <string>
using namespace std;

void maui(string s)
{
    // 进行了拷贝复制
    for (int i = 0; i < s.length(); i++)
    {
        s[i] += 2;
    }
}

void sina(string &s)
{
    // 引用会改变原值
    for (int i = 0; i < s.length(); i++)
    {
        s[i] += 2;
    }
}

void moana(string &s)
{
    // for(char ch : s)中ch是拷贝复制
    for (char ch : s)
    {
        ch += 2;
    }
}

void heihei(string &s)
{
    // 进行了引用复制
    for (char &ch : s)
    {
        ch += 2;
    }
}

string teFiti(string &s)
{
    // 不影响原值
    string result;
    for (char ch : s)
    {
        result += (ch + 2);
    }
    return result;
}

int main()
{
    string s = "umm";

    maui(s);
    cout << s << endl; // "umm"

    s = "umm";
    sina(s);
    cout << s << endl; // "woo"

    s = "umm";
    moana(s);
    cout << s << endl; // "umm"

    s = "umm";
    heihei(s);
    cout << s << endl; // "woo"

    s = "umm";
    teFiti(s);
    cout << s << endl; // "umm"

    return 0;
}
