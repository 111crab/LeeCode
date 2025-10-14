#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0, sum = 0;
        unordered_map<int,int> cnt;
        for(int i =0;i < nums.size();i++){
            sum += nums[i];
            cnt[nums[i]]++;

            int left = i-k+1;
            if(left < 0) continue;

            if(cnt.size() == k) ans = max(ans,sum);

            sum -= nums[left];
            if(--cnt[nums[left]] == 0) cnt.erase(nums[left]);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1,5,4,2,9,9,9};
    cout<<s.maximumSubarraySum(nums,3);
}