/*
 * @lc app=leetcode.cn id=2090 lang=cpp
 *
 * [2090] 半径为 k 的子数组平均值
 */

// @lc code=start
class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        /**
         * 其实就是长度为2k+1的固定区间求属性
         */
        long long sum = 0;
        int ret = 2 * k + 1;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            if ((i - 2 * k) < 0)
                continue;
            ans[i - k] = sum / (ret);
            sum -= nums[i - 2 * k];
        }
        return ans;
    }
};
// @lc code=end
