/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution
{
public:
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
            if (!uset.count(s[i]))
            {
                ++cnt;
                ans = max(ans, cnt);
            }
            else
            {

                // 左指针移动
                while (left < i)
                {
                    if (uset.count(s[i]))
                    {
                        // 如果还包含的话
                        uset.erase(s[left++]);
                        --cnt;
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
};
// @lc code=end
