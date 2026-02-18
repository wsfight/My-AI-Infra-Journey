/*
 * @lc app=leetcode.cn id=2441 lang=cpp
 *
 * [2441] 与对应负数同时存在的最大正整数
 */

// @lc code=start
class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        // 暴力的话从右开始非常简单
        unordered_map<int, int> umap;
        int n = nums.size();
        int ans = -1;
        for (auto x : nums)
        {
            // 思路:只有找到其负值时才是答案
            // 没有找到其负值就++
            if (umap.find(-x) == umap.end())
            {
                // 没有找到负值
                ++umap[x];
            }
            else
            {
                ans = max(ans, abs(x));
            }
        }
        return ans;
    }
};
// @lc code=end
