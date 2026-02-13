#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int minArrivalsToDiscard(vector<int> &arrivals, int w, int m);
int main()
{
    vector<int> v{1, 2, 1, 3, 1};
    int ans = minArrivalsToDiscard(v, 4, 2);
    cout << ans << endl;
    return 0;
}
int minArrivalsToDiscard(vector<int> &arrivals, int w, int m)
{
    /**
     * 窗口长度为w,每个数量不能超过m.超过的即为所得
     */
    int n = arrivals.size();
    unordered_map<int, int> umap; // 用来维护元素数量
    int discardCount = 0;
    for (int i = 0; i < n; ++i)
    {
        // 1.进入窗口
        int &x = arrivals[i]; // 需要修改元素吗?

        if (umap[x] > m)
        {
            // 此时需要丢弃..
            ++discardCount;
            --umap[x]; // 这里为什么不需要?
            x = -1;    // 把丢弃元素设置成-1
        }
        else
        { // 表明此元素在窗口内数量没达到m个
            ++umap[x];
        }
        // 2.窗口扩容
        if (i < (w - 1))
            continue;
        // 3.更新答案
        umap[i - w + 1]--;
    }
    return discardCount;
}