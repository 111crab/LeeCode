#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    string dfs(string s, int &i)
    {
        int multi = 0;
        string res = "";
        while (i < s.size())
        {
            char c = s[i];
            if (c >= '0' && c <= '9')
            {
                multi = multi * 10 + (c - '0');
            }
            else if (c == '[')
            {
                i++;
                string sub_str = dfs(s, i);
                while (multi > 0)
                {
                    res += sub_str;
                    multi--;
                }
            }
            else if (c == ']')
            {
                return res;
            }
            else
            {
                res += s[i];
            }
            i++;
        }
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        return dfs(s, i);
    }
    string decodeString_twoStack(string s) {
        stack<string> st;
        stack<int> plus;
        int multi = 0;
        string ans;
        for (char c : s)
        {
            if (c >= '0' && c <= '9')
            {   
                multi = multi * 10 + (c - '0');
            }
            else if (c == '[')
            {
                st.push(ans);
                plus.push(multi);
                multi = 0;
                ans = "";
            }
            else if (c == ']')
            {
                string last_str = st.top();
                st.pop();
                int cur_multi = plus.top();
                plus.pop();
                string temp = "";
                for (int i = 0; i < cur_multi; i++) temp += ans;
                ans = last_str + temp;
            }
            else
            {
                ans += c;
            }
        }
        return ans;
    }
};