#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int countCompleteSubarrays(std::vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int> all_cnt;
        for (auto& num : nums) all_cnt[num]++;
        int k = all_cnt.size();
        unordered_map<int , int> cnt;
        int left = 0;
        int ans = 0;
        for (int right = 0; right < n ; right++)
        {
            int num = nums[right];
            cnt[num]++;
            while (cnt.size() == k)
            {
                if (--cnt[nums[left]] == 0) cnt.erase(nums[left]);
                left++;
            }
            ans += left;
        }
        return ans;
        
    }
};
