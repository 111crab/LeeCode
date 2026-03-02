
#include <algorithm>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = INT_MIN;
        if (nums.size() == 0) return 0;
        for (auto x : st)
        {
           if (st.find(x-1) != st.end())
           {
               continue;
           }
            int y = x + 1;
            while (st.find(y) != st.end()) y++;
            ans = max(ans, y - x);
        }
        return ans;
    }
};