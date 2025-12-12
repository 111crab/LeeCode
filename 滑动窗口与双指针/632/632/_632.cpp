#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> pairs;
        for (int i = 0 ; i < nums.size(); i++)
        {
            for (int num : nums[i])
            {
                pairs.emplace_back(num,i);
            }
        }

        sort(pairs.begin(),pairs.end());

        
        int ans_l = pairs[0].first;
        int ans_r = pairs.back().first;
        int left = 0;
        int less = nums.size();
        unordered_map<int,int> cnt;
        for (auto [r,i] : pairs)
        {
            if (cnt[i] == 0) less--;
            cnt[i]++;
            while(less == 0)
            {
                auto [l,i] = pairs[left];
                if (r - l < ans_r - ans_l )
                {
                    ans_l = l;
                    ans_r = r;
                }
                cnt[i]--;
                if (cnt[i] == 0) less++;
                left++;
            }
        }
        return {ans_l,ans_r};
    }
};



int main()
{
    Solution s;
    /*vector<vector<int>> nums = {[4,10,15,24,26], [0,9,12,20], [5,18,22,30]};
    s.smallestRange()*/
}