/*
 * @lc app=leetcode.cn id=1493 lang=cpp
 *
 * [1493] 删掉一个元素以后全为 1 的最长子数组
 */

// @lc code=start
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        /**
         * 换个思路是不是区间[left,right]内
         * 只能小于等于1个0
         */
        int n = nums.size();
        int left = 0;
        int ans = 0;
        unordered_map<int, int> umap;
        for (int right = 0; right < n; ++right)
        {
            int c = nums[right];
            ++umap[c];
            while (umap[0] > 1)
            { // 当0的个数超过1的时候收缩边界
                --umap[nums[left++]];
            }
            ans = max(right - left, ans); // 必须要删除一个元素..
        }
        return ans;
    }
};
// @lc code=end
