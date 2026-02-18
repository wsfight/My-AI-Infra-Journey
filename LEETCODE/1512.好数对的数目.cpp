/*
 * @lc app=leetcode.cn id=1512 lang=cpp
 *
 * [1512] 好数对的数目
 */

// @lc code=start
class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        /**
         * 思路:
         */
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> umap;
        for (int i = 0; i < n; ++i)
        {
            ans += umap[nums[i]];
            ++umap[nums[i]];
        }
        return ans;
    }
};
// @lc code=end
