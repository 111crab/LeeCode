#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto str : strs)
        {
            string sorted_s = str;
            sort(sorted_s.begin(), sorted_s.end());
            m[sorted_s].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto& p : m)
        {
            ans.push_back(p.second);
        }
        return ans;
    }
};
