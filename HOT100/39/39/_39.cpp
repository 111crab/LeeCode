#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    
    void dfs(vector<int>& candidates, int sum, int target, int i)
    {
        if (sum == target)
        {
            ans.push_back(path);
            return;
        }
        if (i == candidates.size() || sum > target) return;
        // not chose
        dfs(candidates, sum,target, i + 1);
        
        // chose
        sum += candidates[i];
        path.push_back(candidates[i]);
        dfs(candidates, sum, target, i);
        sum -= candidates[i];
        path.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target, 0);
        return ans;
    }
};