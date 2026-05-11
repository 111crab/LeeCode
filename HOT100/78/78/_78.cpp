#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    
    void backtrack(vector<int>& nums, int start)
    {
        // 每个节点都是一个新的答案
        ans.push_back(path);
        // 选与不选
        for (int i = start; i < nums.size(); i++)
        {
            // 选择 i 位置的数
            path.push_back(nums[i]);
            // 在已经选上 i 的情况下，得到带着 i 的所有 ans
            backtrack(nums, i+1);
            // 不选 i 位置的数字
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};