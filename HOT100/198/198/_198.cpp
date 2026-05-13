#include <vector>
using namespace std;

class Solution {
public:
    // dp[i]: 在考虑第 i 个店铺的时候，最高的金额。
    // [考虑]：选或者不选
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n + 1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            
        }
        return dp[n - 1];
    }
    // 空间优化版
    int rob_space(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n + 1, 0);
        int f0 = nums[0]; // 上上个
        int f1 = max(nums[0], nums[1]); // 上一个
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(f1,  f0+ nums[i]);
            f0 = f1;
            f1 = dp[i];
        }
        return f1;
    }
};