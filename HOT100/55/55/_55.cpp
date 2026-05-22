#include <vector>
using namespace std;

class Solution {
public:
    vector<int> mem;

    // dfs i : 从 i 出发能到达终点吗
    // mem[i] : 从 i 出发能到达终点吗
    bool dfs(vector<int>& nums, int i)
    {
        // 越界和正好到达终点都可
        if (i >= nums.size() - 1) return true;
        // 没法跳点，而且还没走到终点
        if (nums[i] == 0) return false;

        // 记忆化
        if (mem[i] != -1) return mem[i];

        // 查看我能去的其他 i 能不能到达终点。
        int step = nums[i];
        while (step > 0)
        {
            if (dfs(nums, i + step))
            {
                // 我能去的某个 i + step 能到终点，证明我也能去
                return mem[i] = 1;
            }
            step--;
        }
        // 能尝试的都尝试了，证明我去不了
        return mem[i] = 0;
    }
    bool canJump_self(vector<int>& nums) {
        mem.assign(nums.size(), -1);
        return dfs(nums, 0);
    }

    bool canJump(vector<int>& nums) {
        int pre_maxReach = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > pre_maxReach) return false;

            pre_maxReach = max(pre_maxReach, i + nums[i]);
            
            if (pre_maxReach >= nums.size() - 1) return true;
        }
        return true;
    }
};