#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> cnt_p;
        unordered_map<char,int> cnt_windows;
        vector<int> ans;
        int j = 0;
        for(char c : p) cnt_p[c]++;
        for(int i = 0;i < s.size();i++){
            cnt_windows[s[i]]++;

            int left = i - p.size() + 1;
            if(left < 0) continue;

            if(cnt_p == cnt_windows) ans.push_back(left);

            if(--cnt_windows[s[left]] == 0) cnt_windows.erase(s[left]);
        }
        return ans;
    }
};

int main()
{
    Solution S;
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> ans = S.findAnagrams(s, p);
    for (int i : ans) cout << i << " ";
    
    
}