#include <stdio.h>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    string longestNiceSubstring(string s) {
        int len = s.length();
        int ans_len = 0;
        string result;
        unordered_map<char, int> cnt;
        for (int i = 0; i < len; i++) cnt[s[i]]++;
        bool all_valid = true;
        for (int i = 0; i < len; i++)
        {
            char c = s[i];
            if (!FindPair(c,cnt))
            {
                all_valid = false;
            }
        }
        if (all_valid) return s;

        int substr_start = 0;
        for (int i = 0; i <= len; i++)
        {
            char c = s[i];
            if (!FindPair(c,cnt) || i == len)
            {
                if (i > substr_start)
                {
                    string substr = s.substr(substr_start, i - substr_start);
                    if (ans_len < longestNiceSubstring(substr).size())
                    {
                        result = longestNiceSubstring(substr);
                        ans_len = longestNiceSubstring(substr).size();
                    }
                }
                substr_start = i + 1;
            }
        }
        return result;
    }

    bool FindPair(char c, unordered_map<char, int> cnt)
    {
        if (c >= 'a' && c <= 'z')
        {
            if (!cnt[(c - 32)]) return false;
        }
        if (c >= 'A' && c <= 'Z')
        {
            if (!cnt[(c + 32)]) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string ss = "YazaAay";
    cout << s.longestNiceSubstring(ss);

    
}