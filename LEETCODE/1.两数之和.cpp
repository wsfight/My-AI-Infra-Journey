/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        /**
         * 不能排序,排序了原来的索引就丢失了
         * 暴力解法可以.
         */
        unordered_map<int, int> umap;
        int i = 0;
        int n = nums.size();
        for (; i < n; ++i)
        {
            auto it = umap.find(target - nums[i]);
            if (it != umap.end())
            {
                // 找到了
                return {it->second, i};
            }
            umap[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end
