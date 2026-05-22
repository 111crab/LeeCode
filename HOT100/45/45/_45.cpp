#include <vector>
using namespace std;

class Solution {
public:
    vector<int> mem;
    const int INF = 1e9;
    int dfs(vector<int>& nums, int i)
    {
        if (i >= nums.size() - 1)
        {
            return 0;
        }
        if (mem[i] != -1) return mem[i];

        int step = nums[i];
        int min_jump = INF;
        while (step > 0)
        {
            min_jump = min(min_jump, dfs(nums, i + step) + 1);
            step --;
        }
        mem[i] = min_jump;
        return mem[i];
    }
    int jump_self(vector<int>& nums) {
        int n = nums.size();
        mem.assign(n, -1);
        return dfs(nums, 0);
    }

    // 贪心
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int counts = 0;
        int maxCanReach = 0;
        int curTime_jumpDistance = 0;
        for (int i = 0; i < n; i++)
        {
            maxCanReach = max(maxCanReach, i + nums[i]);

            if (i == curTime_jumpDistance)
            {
                counts ++;
                curTime_jumpDistance = maxCanReach;
                if (curTime_jumpDistance >= n - 1) break;
            }
        }
        return counts;
    }
};