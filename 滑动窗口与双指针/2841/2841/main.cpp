#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long sum = 0;
        long long ans = 0;
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            map[nums[i]]++;

            int left = i-k+1;
            if (left<0) continue;

            if (map.size() >= m) ans = max(ans,sum);

            sum -= nums[left];
            if (--map[nums[left]]==0) map.erase(nums[left]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums{2,6,7,3,1,7};
    cout<<s.maxSum(nums, 3, 4);
    
}
