/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        /**
         * 换个思路:定长为cardPoints.size()-k 的最小和滑动窗口
         * 从两边取的话可以转换成对立长度的固定窗口
         */
        // int n = cardPoints.size();
        // int nr = n - k;
        // int tempSum = 0;
        // int sumVector = std::accumulate(cardPoints.begin(), cardPoints.end(), 0);
        // int ans = sumVector;
        // if (k == n)
        //     return ans;
        // for (int i = 0; i < n; ++i)
        // {
        //     tempSum += cardPoints[i];
        //     if (i < (nr - 1))
        //         continue;
        //     ans = min(tempSum, ans);
        //     tempSum -= cardPoints[i - nr + 1];
        // }
        // return sumVector - ans;

        // 以下是答案优雅的做法
        // 其实总体思路不变:改成区间(n - k)内和最小
        int n = cardPoints.size();
        int nr = n - k;
        int sum0 = std::accumulate(cardPoints.begin(), cardPoints.begin() + nr, 0);
        int sum = sum0;
        int ans = sum;
        for (int i = nr; i < n; ++i)
        {
            sum += (cardPoints[i] - cardPoints[i - nr]);
            // 上述可能加了个负数
            // 不需要判断窗口大小了.
            ans = min(sum, ans);
        }
        return std::accumulate(cardPoints.begin(), cardPoints.end(), 0) - ans;
    }
};
// @lc code=end
