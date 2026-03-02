#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(std::vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i< nums.size(); i++)
        {
            int match = target - nums[i];
            if (mp.find(match) != mp.end())
            {
                return {mp[match], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
