#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> cnt_s1;
        int m = s1.size();
        if (m>s2.size()) return false;
        for (char c : s1)
        {
            cnt_s1[c]++;
        }
        unordered_map<char,int> cnt_ans;
        for (int i = 0 ;i < s2.size(); i++)
        {
            cnt_ans[s2[i]]++;

            if (i - m +1 <0) continue;

            if (cnt_ans == cnt_s1) return true;

            if (--cnt_ans[s2[i-m+1]] == 0)
            {
                cnt_ans.erase(s2[i-m+1]);
            }
        }
        return false;
    }
};