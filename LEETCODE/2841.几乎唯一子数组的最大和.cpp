/*
 * @lc app=leetcode.cn id=2841 lang=cpp
 *
 * [2841] 几乎唯一子数组的最大和
 */

// @lc code=start
class Solution
{
public:
    long long maxSum(vector<int> &nums, int m, int k)
    {
        /**
         * 1.固定长度k
         * 2.要求区间内必须有m个不重复的数
         * 3.返回其最大和
         */
        // 只用unordered_map来计数
        int n = nums.size();
        unordered_map<int, int> umap;
        long long sum = 0;
        long long ans = 0;
        for (int i = 0; i < n; ++i)
        {
            // 进入元素,我该怎么判断.
            int num = nums[i];
            sum += num;
            umap[num]++;
            if (i < (k - 1))
                continue;
            if (umap.size() >= m)
            {
                // 说明已经至少有m个不重复的元素
                ans = max(sum, ans);
            }
            int out = nums[i - k + 1];
            sum -= out;
            if ((--umap[out]) == 0)
            {
                umap.erase(out);
            }
        }
        return ans;
    }
};
// @lc code=end
