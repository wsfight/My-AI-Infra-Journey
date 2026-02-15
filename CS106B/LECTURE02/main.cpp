#include <iostream>
#include <string>
using namespace std;
string middlePart(string str);
int main()
{
    string str = "hello,world!";
    cout << "middlePart :" << middlePart(str) << endl; // ello,world
    return 0;
}
string middlePart(string str)
{
    // str.length() >= 3
    int n = str.length();
    return str.substr(1, n - 2);
}