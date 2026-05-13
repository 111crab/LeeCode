#include <vector>
using namespace std;

class Solution {
public:
    
    int dfs(vector<int>& nums, vector<int>& mem, int i)
    {
        if (mem[i] > 0) return mem[i];
        
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                mem[i] = max(mem[i], dfs(nums, mem, j));
            }
        }
        mem[i]++;
        return mem[i];
    }
    int lengthOfLIS_mem(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> mem(n,0);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans = max (ans, dfs(nums, mem, i));
        }
        return ans;
    }


    
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j]);
            }
            dp[i]++;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans = max (ans, dp[i]);
        }
        return ans;
    }
};