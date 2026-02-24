/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        /**
         * 意思就是前k个元素是否有元素相同
         * 滑动窗口吗?
         */
        int n = nums.size();
        unordered_map<int, int> umap;
        for (int i = 0; i < n; ++i)
        {
            auto it = umap.find(nums[i]);
            if (it != umap.end() && umap[nums[i]] > 0)
            {
                return true;
            }
            else
            {
                // 没找到
                umap[nums[i]] += 1;
            }
            if (i < (k))
            {
                continue;
            }
            auto c = nums[i - k];
            umap[c] -= 1;
        }
        return false;
    }
};
// @lc code=end
