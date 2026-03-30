#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> m;
        int ans = 0;
        int left = 0;
        if (s.length() == 0) return 0;
        for (int i = 0 ; i < s.length() ; i++)
        {
            char c = s[i];
            m[c]++;
            while (m[c] > 1)
            {
                m[s[left++]]--;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};