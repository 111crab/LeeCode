#include <vector>

class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int k) {

        long long ans = 0;
        int left = 0;
        int max_num = -1;
        for (int num : nums)
        {
            if (num > max_num) max_num = num;
        }
        int CurrentMaxCount = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            int a = nums[right];
            if (a == max_num) CurrentMaxCount++;

            while (CurrentMaxCount >= k)
            {
                if (nums[left] == max_num) CurrentMaxCount--;
                left ++;
            }

            ans += left;
        }
        return ans;
    }
};
