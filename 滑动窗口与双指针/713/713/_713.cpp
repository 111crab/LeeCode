#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1 ) return 0;
        int cur_multiple = 1;
        int ans = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            cur_multiple *= nums[right];
            
            while (cur_multiple >= k)
            {
                cur_multiple /= nums[left++];
            }

            ans += right - left + 1;
        }
        return ans;
    }
};

int main()
{
    
}