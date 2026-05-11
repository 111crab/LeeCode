#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, int first)
    {
        if(first == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i = first;i < nums.size();i++)
        {
            swap(nums[first],nums[i]);
            backtrack(nums, first+1);
            swap(nums[first],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        backtrack(nums,0);
        return ans;
    }
};