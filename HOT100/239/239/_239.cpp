#include <deque>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        deque<int> q;
        for (int i = 0 ; i < n; i++)
        {
            // in
            while (!q.empty() && nums[q.back()] <= nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);
            // out
            int left= i - k + 1;
            if (q.front() < left)
            {
                q.pop_front();
            }
            // refresh ans
            if (i >= k - 1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,3,-1,-3,5,3,6,7};
    s.maxSlidingWindow(v,3);
}