#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;




class Solution {
public:
    int minimumDifference(std::vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(),[](int a, int b) {return a<b;});
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            int left = i - k + 1 ;
            if (left<0) continue;

            ans = min(ans, nums[i] - nums[left]);
            
        }
        return ans;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {9,4,1,7};
    cout<<s.minimumDifference(nums, 2);
}