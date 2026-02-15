#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;
int lengthOfLongestSubstring(string s);
int main()
{
    string s = "pwwkew";
    int ans = lengthOfLongestSubstring(s);
    cout << ans << endl;
    return 0;
}
int lengthOfLongestSubstring(string s)
{
    int cnt = 0;
    int ans = 0;
    unordered_set<char> uset;
    int left = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        /**
            1.判断是否在容器中.
            1.1 是 goto 2
            1.2 不在. 加入容器,右指针右移
            2.移动左指针,每个左指针的元素在容器内-1.
        */
        if (uset.find(s[i]) == uset.end())
        {
            ++cnt;
        }
        else
        {
            ans = max(ans, cnt);
            // 左指针移动
            while (left < i)
            {
                if (uset.find(s[i]) != uset.end())
                {
                    // 如果还包含的话
                    uset.erase(s[left++]);
                }
                else
                {
                    // 如果不包含了话
                    break;
                }
            }
        }
        uset.insert(s[i]);
    }
    return ans;
}