/*
 * @lc app=leetcode.cn id=1343 lang=cpp
 *
 * [1343] 大小为 K 且平均值大于等于阈值的子数组数目
 */

// @lc code=start
class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        /**
         * 求固定长度k内数组的某一个属性
         * 固定滑动窗口
         */
        int n = arr.size();
        double sum = 0;
        double sum_comp = threshold * k;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += arr[i];
            if ((i - k + 1) < 0)
                continue;
            if (sum >= sum_comp)
                ++ans;
            sum -= arr[i - k + 1];
        }
        return ans;
    }
};
// @lc code=end
