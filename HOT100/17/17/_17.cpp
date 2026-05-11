#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static constexpr  string MAPPING[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    string path;
    
    void dfs(string digits, int i)
    {
        if (i == digits.size())
        {
            ans.push_back(path);
            return;
        }
        for (char c : MAPPING[digits[i] - '0'])
        {
            path.push_back(c);
            dfs(digits,i+1);
            path.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        dfs(digits, 0);
        return ans;
    }
};