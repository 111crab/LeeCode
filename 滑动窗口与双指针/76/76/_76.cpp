#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        // early return
        if (n<m) return "";
        unordered_map<char,int> cnt_t;
        for (char c : t) cnt_t[c]++;
        // common flow
        unordered_map<char,int> cnt; // for current window
        unordered_map<char,bool> flag; // flag for the key is satisfied or not
        int left = 0;
        int index = 0; // how many key are satisfied
        int left_ans = -1, right_ans = n;
        for (int right = 0; right < n; right++)
        {
            char c = s[right];
            if (cnt_t.find(c) != cnt_t.end())
            {
                cnt[c]++;
                // index control -- in
                if (cnt[c] >= cnt_t[c] && flag[c] == false)
                {
                    flag[c] = true;
                    index++;
                }
            }
            // as long as current window valid 
            while (index == cnt_t.size())
            {
                // look for shorter ans
                if (left_ans == -1)
                {
                    left_ans = left;
                    right_ans = right;
                }
                if (left_ans != -1 && right_ans - left_ans > right - left)
                {
                    left_ans = left;
                    right_ans = right;
                }
                char c_left = s[left];
                // index control -- out
                if (cnt_t.find(c_left) != cnt_t.end()) // can find key 
                {
                    cnt[c_left]--;
                    if (cnt[c_left] < cnt_t[c_left] && flag[c_left] == true)
                    {
                        index--;
                        flag[c_left] = false;
                    }
                }
                left++;
            }
        }
        return left_ans < 0 ? "" : s.substr(left_ans, right_ans - left_ans + 1);
    }
};