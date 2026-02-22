/*
 * @lc app=leetcode.cn id=624 lang=cpp
 *
 * [624] 数组列表中的最大距离
 */

// @lc code=start
class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        /**
         * 此题是数组中的最大差值
         */
        int maxSum = arrays[0].back();
        int minSum = arrays[0][0];
        int tempAns = 0;
        int ans = 0;
        int n = arrays.size();
        for (int i = 1; i < n; ++i)
        {
            int tempMax = arrays[i].back();
            int tempMin = arrays[i][0];
            tempAns = max(abs(tempMax - minSum), abs(tempMin - maxSum));
            maxSum = max(maxSum, tempMax);
            minSum = min(minSum, tempMin);
            ans = max(tempAns, ans);
        }
        return ans;
    }
};
// @lc code=end
