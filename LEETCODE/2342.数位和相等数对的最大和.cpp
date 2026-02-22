/*
 * @lc app=leetcode.cn id=2342 lang=cpp
 *
 * [2342] 数位和相等数对的最大和
 */

// @lc code=start
class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        /**
         * 要求:
         * 1.数位和相同
         * 2.数位和相同后最大值
         */
        /**
         * 要求:
         * 1.数位和相同
         * 2.数位和相同后最大值
         */
        unordered_map<int, int> umap;
        int n = nums.size();
        int ans = -1;
        for (int i = 0; i < n; ++i)
        {
            auto it = umap.find(cnt(nums[i]));
            if (it == umap.end())
            {
                // 不相同
                // 哈希表记录
                umap[cnt(nums[i])] = i;
            }
            else
            {
                // 相同
                int x = cnt(nums[i]); // 计算和
                int y = umap[x];      // 对应索引
                ans = max(ans, nums[i] + nums[y]);
                if (nums[i] > nums[y])
                {
                    umap[cnt(nums[i])] = i;
                }
            }
        }
        return ans;
    }
    int cnt(int a)
    {
        int cnta = 0;
        while (a != 0)
        {
            cnta += (a % 10);
            a = (a / 10);
        }
        return cnta;
    }
};
// @lc code=end
