#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    // 暴力模型: 计算每个高度的最大矩形，这个最大矩形可能会在当前高度向左右延伸。
    // 单调栈应用: ( 此处为单调递增 )
    // 1.当前 i 只要小于栈顶，就能把栈顶这个高度的最大矩形确定（因为单调递增，且当前 i 的 h 小于栈顶，栈顶又是单增的，所以无法左右延伸，面积被锁定）
    // 2.因为 1. 构造出的 stack 就是单增的
    // 3.stack 存储的下标，因为小标既能访问高度，又能计算宽度
    // 4.使用两个哨兵 0 作为左右高度边界，就能配合 [单调栈] 考虑全部的高度了
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> new_heights(n + 2, 0);
        for (int i = 0; i < n; i++) new_heights[i + 1] = heights[i];
        int ans = 0;
        
        for (int i = 0; i < n + 2; i++)
        {
            int h = new_heights[i];
            while (!st.empty() && h < new_heights[st.top()])
            {
                int cur_h = new_heights[st.top()];
                st.pop();
                ans = max(cur_h * (i - st.top() - 1), ans);
            }
            if (!st.empty() && h == new_heights[st.top()]) st.pop();
            st.push(i);
        }
        return ans;
    }
};