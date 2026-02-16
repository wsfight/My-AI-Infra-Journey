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
        // 不定长数组,越长越合理
        int n = s.length();
        unordered_map<char, int> umap;
        int left = 0;
        int ans = 0;
        for (int right = 0; right < n; ++right)
        {
            char c = s[right];
            ++umap[c];
            while (umap[c] > 1)
            {
                // 窗口内有重复元素
                --umap[s[left++]];
            }
            // 直到窗口内没有重复元素
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end
