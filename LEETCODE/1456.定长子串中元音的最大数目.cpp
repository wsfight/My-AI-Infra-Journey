/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
 */

// @lc code=start
class Solution
{
public:
    int maxVowels(string s, int k)
    {
        /**
         * 给定长度区间为k.可以考虑定长
         * 滑动窗口
         */
        // 1.创建一个记录数量的变量和结果变量
        int cnt = 0;
        int ans = 0;
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        // 2.开始循环
        for (int i = 0; i < s.size(); i++)
        {
            // 2.1.先进来一个元素
            if (vowels.contains(s[i]))
            {
                ++cnt;
            }
            if ((i - k + 1) < 0)
                continue; // 表明小区间内值不够
            ans = max(cnt, ans);
            if (vowels.contains(s[i - k + 1]))
            {
                --cnt;
            }
        }
        return ans;
    }
};
// @lc code=end
