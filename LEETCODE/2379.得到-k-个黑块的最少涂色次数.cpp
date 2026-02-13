/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 *
 * [2379] 得到 K 个黑块的最少涂色次数
 */

// @lc code=start
class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        /**
         * 1.固定长度区间k
         * 2.找出区间长度k中出现白色块数最少的数量
         */
        int n = blocks.size();
        int cnt = 0;
        int ans = n;
        for (int i = 0; i < n; ++i)
        {
            if (blocks[i] == 'W')
                ++cnt;
            if (i < (k - 1))
                continue;
            ans = min(ans, cnt);
            if (blocks[i - k + 1] == 'W')
                --cnt;
        }
        return ans;
    }
};
// @lc code=end
