#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    
    int dfs(string& s, vector<int>& mem,int i)
    {
        if (i <= 0 || s[i] == '(') return 0;
        if (mem[i] != -1) return mem[i];
        
        if (s[i - 1] == '(') mem[i] = dfs(s, mem, i - 2) + 2;
        else
        {
            int insert_len = dfs(s, mem, i - 1);
            int match_idx = i - insert_len - 1;
            
            if (match_idx >= 0 && s[match_idx] == '(') mem[i] = 2 + insert_len + dfs(s, mem, match_idx - 1);
            else
            {
                mem[i] = 0;
            }
        }
        return mem[i];
    }
    
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> mem(n, -1);
        dfs(s, mem, 0);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans = max(ans , dfs(s, mem , i));
        }
            
        return ans;
    }
};