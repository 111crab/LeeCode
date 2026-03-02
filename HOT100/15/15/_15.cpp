#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int x = nums[i];
            if (i > 0 && x == nums[i - 1]) continue;
            int target = 0 - nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum == target)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    ans.push_back(temp);
                    while (left < right && nums[left] == nums[left+1]) left++; 
                    while (right > left && nums[right] == nums[right-1]) right--;
                }
                if (sum > target) right--;
                else left++;
            }
        }
        return ans;
    }
};