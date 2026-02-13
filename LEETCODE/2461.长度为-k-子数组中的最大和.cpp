/*
 * @lc app=leetcode.cn id=2461 lang=cpp
 *
 * [2461] 长度为 K 子数组中的最大和
 */

// @lc code=start
class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        /**
         * 1.固定长度k
         * 2.要求满足k个不同的元素
         */
        int n = nums.size();
        long long tempSum = 0;
        long long ans = 0;
        unordered_map<int, int> umap; // 用来计数
        for (int i = 0; i < n; ++i)
        {
            umap[nums[i]] += 1;
            tempSum += nums[i];
            if (i < (k - 1))
            {
                continue;
            }
            if (umap.size() == k)
            {
                ans = max(ans, tempSum);
            }
            int out = nums[i - k + 1];
            tempSum -= out;
            if (--umap[out] == 0)
            {
                umap.erase(out);
            }
        }
        return ans;
    }
};
// @lc code=end
