#include <vector>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> f_min(n);
        vector<int> f_max(n);
        f_min[0] = nums[0];
        f_max[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < 0)
            {
                f_max[i] = max(nums[i] * f_min[i - 1], nums[i]);
                f_min[i] = min(nums[i] * f_max[i - 1], nums[i]);
            }
            else
            {
                f_max[i] = max(nums[i] * f_max[i - 1], nums[i]);
                f_min[i] = min(nums[i] * f_min[i - 1], nums[i]);
            }
        }
        int ans = nums[0];
        for (int i = 1; i < n; i++) ans = max(ans, f_max[i]);
        return ans;
    }
};