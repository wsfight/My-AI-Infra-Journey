/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

// @lc code=start
class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        /**
         * 要求是无序集合中2个元素相等
         * 怎么维护集合?
         */
        int n = dominoes.size();
        int cnt[10][10]{};
        int ans = 0;
        for (auto &x : dominoes)
        {
            auto [a, b] = minmax(x[0], x[1]);
            ans += cnt[a][b];
            ++cnt[a][b];
        }
        return ans;
    }
};
// @lc code=end
