/*
 * PigLatin (Code Write)
 * ---------------------
 * Write TWO functions that convert a string INPUT into its
 * pig-Latin form. To convert a word into pig-Latin, follow these
 * steps:
 * 1. Split INPUT into 2 parts, the string of letters BEFORE the
 *    first vowel, and the string of letters AFTER (and including) the
 *    first vowel.
 * 2. Append the before-string to the after-string.
 * 3. Append "ay" to this resulting string.
 *
 * You may assume your input is a single, valid word with no trickery.
 *
 * Both functions below should have the same functionality, but pigLatinReturn()
 * expects a new string in return that is the pig-Latin form of INPUT, and
 * pigLatinReference() expects the parameter INPUT to be modified by the function call.
 */
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
const string vowels = "aeiouAEIOU";
unordered_set<char> uset{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
bool isVowel(char c)
{
    return vowels.find(c) != string::npos;
}
string pigLatinReturn(string input)
{ /***
      1.意思是把字符串截成2段,第一段为第一个元音前,第二段为第一个元音后(包括元音)
      2.把一段加到第二段后
      3.接下来再在结尾加个py
  */
    string ans = "";
    // 首先找到第一个元音的索引
    int index = -1;
    for (int i = 0; i < input.length(); ++i)
    {
        if (uset.count(input.at(i)))
        {
            index = i;
            break;
        }
    }
    if (index == -1)
        return ans;
    ans += input.substr(index);
    ans += input.substr(0, index);
    ans += "ay";
    return ans;
}

void pigLatinReference(string &input)
{
    // 就地修改
    int index = -1;
    for (int i = 0; i < input.length(); ++i)
    {
        if (isVowel(input.at(i)))
        {
            index = i;
            break;
        }
    }
    string temp = input.substr(0, index);
    input = input.substr(index);
    input += temp;
    input += "ay";
}
int main()
{
    string input = "yasmine";
    cout << pigLatinReturn(input) << endl;
    string input1 = "yasmine";
    pigLatinReference(input1);
    cout << input1 << endl;

    return 0;
}