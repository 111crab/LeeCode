#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        int n = height.size();
        for (int i = 0; i < n; i++)
        {
            int current_h = height[i];
            while (!st.empty() && height[st.top()] <= current_h)
            {
                int bottom_h = height[st.top()];
                st.pop();
                if (st.empty()) break;
                int left_index = st.top();
                ans += (min(current_h, height[left_index]) - bottom_h) * (i - left_index - 1);
            }
            st.push(i);
        }
        return ans;
    }
};