#include <iostream>
using namespace std;

bool IsYuanYin(char c)
{
    if (c == 'a' ||c == 'e' ||c == 'i' ||c == 'o' ||c == 'u') return true;
    else return false;
}

//垃圾双循环的搞法！！！

class Solution_self {
public:
    int maxVowels(string s, int k) {
        int temp = 0,j = 0,ans = -1,m = 0;
        for (int i = 0; i <= s.length() - k; i++)
        {
            j = k;
            m = i;
            temp = 0;
            while (j>=1)
            {
                if (IsYuanYin(s[m++])) temp++;
                j--;
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};

// 最优的AC代码：灵神！！！！！
class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int Vowels = 0;
        for (int i = 0; i < s.length(); i++)
        {
            // 1.右端点进入：判断右端点是否为元音。
            if (s[i] == 'a' ||s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u') Vowels++;
            
            
            int left = i-k+1;  // i-k+1：当i为右端点的时候，长度为k的子串的左端点为LEFT
            if (left < 0) continue; // 判断是否形成一个长度为k的窗口，最开始的时候一个一个判断的，还不足k的长度。

            // 2.更新答案
            ans = max(ans,Vowels);
            if (ans == k) break; // 答案为最大窗口直接break无需再继续

                
            // 3.左端点离开窗口
            if (s[left] == 'a' ||s[left] == 'e' ||s[left] == 'i' ||s[left] == 'o' ||s[left] == 'u') Vowels--;
            
        }
        return ans;
    }
};



int main()
{

    Solution s;
    cout<<s.maxVowels("abciiidef",3);
    
    return 0;
}