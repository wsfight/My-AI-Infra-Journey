/*
 * @lc app=leetcode.cn id=3679 lang=cpp
 *
 * [3679] 使库存平衡的最少丢弃次数
 */

// @lc code=start
class Solution
{
public:
    int minArrivalsToDiscard(vector<int> &arrivals, int w, int m)
    {
        /**
         * 窗口长度为w,每个数量不能超过m.超过的即为所得
         */
        // int n = arrivals.size();      // 数组长度
        // unordered_map<int, int> umap; // 用来维护每个物品的数量
        // int discardCount = 0;
        // for (int i = 0; i < n; ++i)
        // {
        //     umap[arrivals[i]]++;
        //     if (i < (w - 1))    // 窗口长度不够
        //         continue;
        //     for (auto &x : umap)
        //     {
        //         if (x.second > m)
        //         {
        //             ans = min(ans, x.second - m);
        //             x.second -= 1;   // 其实这段代码并没有真正的删除..
        //         }
        //     }
        //     int out = arrivals[i - w + 1];
        //     umap[out]--;
        // }
        // if (ans == n)
        //     return 0;
        // return ans;
        int n = arrivals.size();
        unordered_map<int, int> umap; // 用来维护元素数量
        int discardCount = 0;
        for (int i = 0; i < n; ++i)
        {
            // 1.进入窗口
            int &x = arrivals[i]; // 需要修改元素吗?

            if (umap[x] == m)
            {
                // 此时需要丢弃..
                ++discardCount;
                x = -1; // 把丢弃元素设置成-1
            }
            else
            { // 表明此元素在窗口内数量没达到m个
                ++umap[x];
            }
            // 2.窗口扩容
            if (i < (w - 1))
                continue;
            // 3.更新答案
            umap[arrivals[i - w + 1]]--;
        }
        return discardCount; //  最少需要一共丢弃多少个
    }
};
// @lc code=end
