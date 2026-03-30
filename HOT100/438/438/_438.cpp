#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int left = 0;
        unordered_map<char, int> mm;
        unordered_map<char, int> pp;
        for (auto c : p)
        {
            pp[c]++;
        }
        int win_len = p.length();
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            mm[c]++;
            if (i - left + 1 < win_len)
            {
                continue;
            }

            if (mm == pp) ans.push_back(left);
            
            if (--mm[s[left]] == 0) mm.erase(s[left]);
            left ++;
        }
        return ans;
    }
};

int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    Solution solution;
    solution.findAnagrams(s, p);
}