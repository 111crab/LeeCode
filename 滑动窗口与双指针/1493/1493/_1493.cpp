#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = -1;
        int left = 0;
        int current_len = 0;
        int not_one_cnt = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            current_len++;
            if (nums[i] != 1) not_one_cnt++;
            while (not_one_cnt == 2)
            {
                current_len--;
                if (nums[left] != 1)
                {
                    not_one_cnt --;
                }
                left++;
            }
            ans = max(ans, current_len);
        }
        if (not_one_cnt == 0) return n - 1;
        return ans - 1;
    }
};


int main()
{
    Solution s;
    vector<int> nums = {1,1,1};
    cout<<s.longestSubarray(nums);
}