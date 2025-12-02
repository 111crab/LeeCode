#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int maximumBeauty(std::vector<int>& nums, int k) {
        int ans = -1;
        int left = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end(), [](int a,int b){return a<b;});
        for (int i = 0; i < n; i++)
        {
            while (!(nums[i] - nums[left] <= 2 * k))
            {
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
