#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    // 考虑使用前 i 个物品，塞满 less
    bool dfs(int i, int less, vector<int>& nums, vector<vector<int>>& mem)
    {
        if (less == 0) return true;
        if (less < 0 || i == nums.size()) return false;

        if (mem[i][less] != -1) return mem[i][less];
        
        // chose
        bool res_chosen = dfs(i + 1, less - nums[i], nums, mem);
        // not chosem
        bool res_notChosen = dfs(i + 1, less, nums, mem);

        return mem[i][less] = res_chosen || res_notChosen;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % 2 != 0) return false;
        vector<vector<int>> mem(nums.size(), vector<int>(sum / 2 + 1, -1));
        return dfs(0, sum / 2, nums, mem);
    }
    // 0-1 背包
    bool canPartition_dp(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(int num : nums)
        {
            for (int j = target; j >= num; j--)
            {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};