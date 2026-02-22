/*
 * @lc app=leetcode.cn id=1679 lang=cpp
 *
 * [1679] K 和数对的最大数目
 */

// @lc code=start
class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        /**
         * 本质上还是枚举右,维护左
         * 枚举右,计算k-右
         * 由于可能有重复的元素用umap来维护
         */
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> umap;
        for (auto &x : nums)
        {
            int mx = k - x;
            auto it = umap.find(mx);
            if (it != umap.end() && it->second > 0)
            {
                // 找到了
                ans += 1;
                it->second -= 1;
            }
            else
            {
                // 没找到
                ++umap[x];
            }
        }
        return ans;
    }
};
// @lc code=end
