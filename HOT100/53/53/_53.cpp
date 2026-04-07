#include <inttypes.h>
#include <vector>
using namespace std;
class Solution {
    
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int prefix_sum = 0;
        int min_prefixSum = 0;
        int ans = - INT_MAX;
        for (int i = 0 ; i < nums.size(); i++)
        {
            prefix_sum = prefix_sum + nums[i];
            ans = max(ans , prefix_sum - min_prefixSum);
            min_prefixSum = min(min_prefixSum , prefix_sum);
        }
        return ans;
    }
    
    // dynamic programming
    int maxSubArray_1(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int ans = - INT_MAX;
        ans = max(ans , dp[0]);
        for (int i = 1 ; i < nums.size(); i ++)
        {
            dp[i] = max(nums[i] , max(dp[i - 1], 0) + nums[i]);
            ans = max(ans , dp[i]);
        }
        
        return ans;
    }
};
