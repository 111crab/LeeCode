#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end(),[](int a ,int b){return a < b;});
        int left = 0;
        int max_save = 0;
        if (n == 1) return 0;
        for (int i = 1; i < n; i++)
        {
            while (1LL * nums[left] * k < nums[i] && left < i) 
            {
                left++;
            }
            max_save = max(max_save, i - left + 1);
        }
  
        return n - max_save;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {32,607,740,134,944,91,410,155,493,89,12};
    cout<<s.minRemoval(nums,10);
}