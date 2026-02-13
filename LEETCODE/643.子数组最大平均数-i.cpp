/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        // 在一个固定区间内找属性
        // 一般都是固定滑动窗口
        int sum = 0;
        int ans = -10000000000;
        int n = nums.size();
        int minInt = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            if ((i - k + 1) < 0)
                continue;
            ans = max(sum, ans);
            sum -= nums[i - k + 1];
        }
        return double(ans) / k;
    }
};
// @lc code=end
