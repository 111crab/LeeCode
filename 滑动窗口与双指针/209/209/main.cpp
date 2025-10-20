#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int left = 0;
        int sum = 0;
        int n = nums.size();
        for(int right = 0; right < n; right++){
            sum += nums[right];

            while(sum >= target){
                ans = min(ans , right - left + 1);
                sum -= nums[left];
                left++;
            }

        }
        return  ans <= n ? ans : 0;
    }
};




int main()
{
    Solution s;
    vector<int> nums{2,3,1,2,4,3};
    cout<< s.minSubArrayLen(7,nums);
}


