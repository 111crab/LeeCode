#include <stdio.h>
#include<iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int last = -k - 1;
        // 处理第一个窗口 [0,k-1]
        for (int i = 0; i <= k - 1 ; i++)
        {
            if (nums[i] == key) last = i;
        }
        // 从头开始判断
        for (int i = 0; i < nums.size(); i++)
        {
            if ( i + k < nums.size() && nums[i+k] == key)
            {
                last = i + k;
            }

            if (last >= i - k) ans.push_back(i);
        }
        return ans;
    }
};

int main()
{
    
}