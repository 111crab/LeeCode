#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        int ans = -1;
        int left = 0;
        std::unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            cnt[num]++;
            while (cnt[num] > k)
            {
                if (--cnt[nums[left]] == 0) cnt.erase(nums[left]);
                left++;
            }
            ans = max(ans , i - left + 1);
        }
        return ans;
    }
};
