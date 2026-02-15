#include <iostream>
#include <string>
#include <cctype> // 处理字符串中字符的库
using namespace std;
bool startsWith(string str, string prefix);
string reverseString(string str);
bool isDigitSting(string str);
bool equalIngoreCase(string str1, string st2);
int main()
{
    // string str;
    // cin >> str; // 遇到空格就会结束
    // cout << str << endl;
    // string str1;
    // getline(cin, str1); // 获取一整行
    // cout << "Hello " << str1 << "!" << endl;
    // + 拼接字符串
    string str2 = "hello,world";
    str2 += "d";
    cout << "str2: " << str2 << "!" << endl; // c++是强类型语言
    if (str2 == "quit")
        cout << "equal!" << endl;
    else
        cout << "not equal!" << endl;

    // 对字符串进行索引 1.[]  2.at  第二种更好会进行边界检查
    cout << "第二个字符为:" << str2[1] << endl;
    cout << "第二个字符为:" << str2.at(1) << endl;

    // = 赋值 运算符 在底层是进行赋值拷贝
    string str3 = str2; // 相互独立的

    // 提取子串
    cout << "子串" << str2.substr(1, 4) << endl; // 不影响原字符串
    cout << "str2: " << str2 << endl;

    // 搜索字符串
    cout << "查找字符o: " << str2.find('o') << endl;

    str2[0] = 'a';
    cout << "str2:" << str2 << endl; // 就地修改了

    // startWith函数
    cout << "str3与str2是否相等: " << startsWith(str2, str3) << endl;

    // 循环一个子串创建字符串 2种方法等效的
    string str4(10, 'a');
    cout << "str4: " << str4 << endl;
    string str5 = "";

    for (int i = 0; i < 10; ++i)
    {
        str5 += "a";
    }
    cout << "str5: " << str5 << endl;

    // 逆序字符串
    string str6 = "desserts";
    cout << "逆序str6: " << reverseString(str6) << endl;

    // cctype库
    string str7 = "012345";
    string str8 = "0123a";
    cout << "str7: " << isDigitSting(str7) << endl; // 1
    cout << "str8: " << isDigitSting(str8) << endl; // 0

    string str9 = "ABCD";
    string str10 = "abcd";
    cout << "isequal :" << equalIngoreCase(str9, str10) << endl; // 1

    return 0;
}
bool startsWith(string str, string prefix)
{
    if (str.length() < prefix.length())
        return false;
    int n = prefix.length();
    for (int i = 0; i < n; ++i)
    {
        if (!(str.at(i) == prefix.at(i)))
            return false;
    }
    return true;
}

string reverseString(string str)
{
    string ans = "";
    int n = str.length();
    for (int i = n - 1; i >= 0; --i)
    {
        ans += str.at(i);
    }
    return ans;
}

bool isDigitSting(string str)
{
    // 判断字符串中是否都是数字组成
    int n = str.length();
    for (int i = 0; i < n; ++i)
    {
        if (!isdigit(str.at(i)))
            return false;
    }
    return true;
}

bool equalIngoreCase(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    if (n1 != n2)
        return false;
    for (int i = 0; i < n1; ++i)
    {
        if (!(tolower(str1.at(i)) == tolower(str2.at(i))))
        {
            return false;
        }
    }
    return true;
}
