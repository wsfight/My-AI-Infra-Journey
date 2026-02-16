/*
 * @lc app=leetcode.cn id=3090 lang=cpp
 *
 * [3090] 每个字符最多出现两次的最长子字符串
 */

// @lc code=start
class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        /**
         * 题目要求的是字符最多出现2次
         * 其实可以和题目3一样的思路
         */
        int n = s.length();
        int left = 0;
        int ans = 0;
        unordered_map<char, int> umap;
        for (int right = 0; right < n; ++right)
        {
            char c = s[right];
            ++umap[c];
            while (umap[c] > 2)
            {
                // 说明区间内c的数量多于2
                // 弹出左区间内值
                --umap[s[left++]];
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end
