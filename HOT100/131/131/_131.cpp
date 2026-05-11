#include <atomic>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    
    bool Ispartition(string str)
    {
        int left = 0, right = str.size() - 1;
        while (left < right)
        {
            if (str[left] != str[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void dfs(string s, vector<string> path, int start)
    {
        if (start == s.size())
        {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            string sub = s.substr(start, i - start + 1);
            if (Ispartition(sub))
            {
                path.push_back(sub);
                dfs(s, path, i + 1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        dfs(s, path, 0);
        return ans;
    }
};