#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int left = 0, right = 0;
        for (int i = 0 ; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[left] = nums[i];
                if (i != left) nums[i] = 0;
                left++;
            }
        }
    }
};
