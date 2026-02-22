/*
 * @lc app=leetcode.cn id=2016 lang=cpp
 *
 * [2016] 增量元素之间的最大差值
 */

// @lc code=start
class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int ans = -1;
        int minNum = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; ++i)
        {
            ans = max(nums[i] - minNum, ans);
            minNum = min(minNum, nums[i]);
        }
        return ans ? ans : -1;
    }
};
// @lc code=end
