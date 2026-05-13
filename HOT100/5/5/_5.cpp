#include <string>
using namespace std;

class Solution {
public:

    int expand(string &s, int l, int r)
    {
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            l--;
            r++;
        }
        return r - l - 1;
    }    
    string longestPalindrome(string s) {

        int ans = -1;
        int start = -1;
        for (int i = 0; i < s.size(); ++i)
        {
            int even = expand(s, i, i + 1);
            int odd = expand(s, i, i);

            int cur_max = max(even, odd);
            if (cur_max > ans)
            {
                ans = cur_max;
                start = i - (cur_max - 1) / 2;
            }
        }

        return s.substr(start, ans);
    }
};