/*
 * @lc app=leetcode.cn id=2260 lang=cpp
 *
 * [2260] 必须拿起的最小连续卡牌数
 */

// @lc code=start
class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        /**
         * 就是相同元素之间的最小区间
         */
        int n = cards.size();
        int ans = n + 1;
        unordered_map<int, int> umap;
        for (int i = 0; i < n; ++i)
        {
            auto it = umap.find(cards[i]);
            if (it != umap.end())
            {
                ans = min(ans, i - umap[cards[i]] + 1);
            }
            umap[cards[i]] = i;
        }
        if (ans == n + 1)
        {
            return -1;
        }
        return ans;
    }
};
// @lc code=end
