#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> ans;
    
    void dfs(int n, string path, int left, int right)
    {
        if (right == n)
        {
            ans.push_back(path);
            return;
        }
        if (left < n)
        {
            path[left + right] = '(';
            dfs(n, path, left + 1, right);
        }
        if (right < left)
        {
            path[left + right] = ')';
            dfs(n, path, left, right + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string path(2*n,0);
        dfs(n, path, 0, 0);
        return ans;
    }
};