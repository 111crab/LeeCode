#include <string>
#include <unordered_map>
using namespace std;

// 本题注意：在更新答案的时候，不要直接进行字符串的赋值，而是记录最佳答案的下标，因为可能有溢出的情况
class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "" ;
        int m = s.length(), n = t.length();
        unordered_map <char,int> cnt_t; // 记录 t 串的字符和频次
        unordered_map <char,bool> isSatisfy_t; 
        unordered_map <char,int> cnt_s;
        for (auto c : t)
        {
            cnt_t[c]++;
            isSatisfy_t[c] = false;
        }
        int need_cnt = cnt_t.size();
        int satisfy_index = 0;
        int left = 0;
        int ans_left = -1;
        int ans_len = 0;
        for (int i = 0; i < m; i++)
        {
            // in
            char c = s[i];
            cnt_s[c]++;
            if (cnt_t.find(c) != cnt_t.end())
            {
                if (cnt_s[c] == cnt_t[c] && isSatisfy_t[c] == false)
                {
                    isSatisfy_t[c] = true;
                    satisfy_index++;
                }
            }
            // out
            while (satisfy_index == need_cnt)
            {
                if (ans_left == -1 ||(i - left + 1) < ans_len)
                {
                    ans_left = left;
                    ans_len = i - left + 1;
                }
                char left_char = s[left];
                if (cnt_t.find(left_char) != cnt_t.end())
                {
                    cnt_s[left_char]--;
                    if (cnt_s[left_char] < cnt_t[left_char])
                    {
                        isSatisfy_t[left_char] = false;
                        satisfy_index--;
                    }
                    if (cnt_s[left_char] == 0)
                    {
                        cnt_s.erase(left_char);
                    }
                }
                else
                {
                    if (--cnt_s[left_char] == 0) cnt_s.erase(left_char);
                }
                left ++;
            }
        }
        if (ans_left != -1) ans = s.substr(ans_left, ans_len);
        return ans;
    }
};

int main()
{
    Solution s;
    string ss = "ADOBECODEBANC";
    string tt = "ABC";
    s.minWindow(ss,tt);
}