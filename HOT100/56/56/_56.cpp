#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 合并区间的题目：对于左端点和右端点排序，会出现很好的单调性。
        // 1.左端点排序
        sort(intervals.begin(), intervals.end(),[](const vector<int>& a , const vector<int>& b){return a<b;});
        vector<vector<int>> ans;
        // 2. 遍历右端点，用于固定 ans 的每个区间的右端点
        for (auto & p : intervals)
        {
            // 2.1 能合并：能待测区间的左端点 <= 待定答案区间的右端点 
            if (!ans.empty() && ans.back()[1] >= p[0])
            {
                ans.back()[1] = max(ans.back()[1] , p[1]);
            }
            else
            {
            // 2.2 不能合并，则这个能待测区间的左端点一定是某个答案中的左端点，先加入 ans，再确定其右端点    
                ans.push_back(p);
            }
        }
        return ans;
    }
};