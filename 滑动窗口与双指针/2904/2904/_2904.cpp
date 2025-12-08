#include <algorithm>
#include <iostream>
using namespace std; 


class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int AllOneOfS = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1') AllOneOfS++;
        }
        if (AllOneOfS == 0) return "";
        if (AllOneOfS != 0 && k == 1) return "1";
        if (AllOneOfS != k && k == s.length()) return "";
        if (k == s.length() && AllOneOfS == k) return s;
        int left = 0;
        string ans ;
        int cnt_of_one = 0;
        bool first_valid = false;
        for (int i = 0; i< n; i++)
        {
            char c = s[i];
            if (c == '1') cnt_of_one++;
            if (cnt_of_one == k && first_valid == false)
            {
                ans = s.substr(left, i - left + 1);
                
                first_valid = true;
            }
            if (first_valid == true)
            {
                while (cnt_of_one == k )
                {
                    if (ans.length() > i - left + 1) ans = s.substr(left, i - left + 1);
                    else if (ans.length() == i - left + 1)
                    {
                        string new_str = s.substr(left, i - left + 1);
                        for (int i = 0; i < new_str.length(); i++)
                        {
                            if (ans[i] != new_str[i])
                            {
                                if (ans[i] > new_str[i])
                                {
                                    ans = new_str;
                                    
                                    break;
                                }
                                break;
                            }
                        }
                    }
                    if (s[left] == '1') cnt_of_one--;
                    left++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout<<s.shortestBeautifulSubstring("110101000010110101",3);
}