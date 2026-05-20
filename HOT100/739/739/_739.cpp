#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    // 单调栈的经典应用
    // 堆栈 tmp 存储 [还未找到高于自己温度的那一天 的 index]
    // 当前 i 作为救世主，不断地对比和解救堆栈中的索引
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> tmp;
        vector<int> ans(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++)
        {
            int  t = temperatures[i];
            while (!tmp.empty() && t > temperatures[tmp.top()])
            {
                int last_idx = tmp.top();
                tmp.pop();
                ans[last_idx] = i - last_idx;
            }
            tmp.push(i);
        }
        return ans;
    }
};