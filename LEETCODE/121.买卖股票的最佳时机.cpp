/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        /**
         * 寻找后-前的最大差值
         * 双变量问题
         * 枚举卖出价格
         * 维护最小买入价格
         */
        int ans = 0;
        int minPrice = prices[0];
        for (auto x : prices)
        {
            ans = max(ans, x - minPrice);
            minPrice = min(x, minPrice);
        }
        return ans;
    }
};
// @lc code=end
