
#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestSubstring(string s, int k) {
        int len = s.size();
        if (len < k) return 0;


        unordered_map<char, int> cnt;
        for (char c : s) cnt[c]++;
        
        bool all_valid = true;
        for (auto& pair : cnt)
        {
            if (pair.second < k) all_valid = false;
        }
        if (all_valid) return len;

        int sub_start = 0;
        int ans = 0;
        for (int i = 0; i <= len; i++)
        {
            char cur_char = s[i];
            if (cnt[cur_char] < k || i == len)
            {
                if (i > sub_start)
                {
                    string substr = s.substr(sub_start, i - sub_start);
                    ans = max(ans , longestSubstring(substr,k));
                }
                sub_start = i + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout<< s.longestSubstring("aaabb", 3) << endl;
}