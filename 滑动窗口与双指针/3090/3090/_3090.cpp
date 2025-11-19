#include <stdio.h>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    // 越长越合法
    int maximumLengthSubstring(std::string s) {

        int ans = -1;
        int len = s.length();
        int left = 0;
        int current_sum = 0;
        std::unordered_map<char, int> map;
        for (int i = 0; i < len; i++)
        {
            char c = s[i];
            if (map[c] == 2)
            {
                while (map[c] == 2)
                {
                    map[s[left++]]--;
                    current_sum--;
                }
            }
            map[c]++;
            current_sum++;
            ans = std::max(ans,current_sum);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    cout<< s.maximumLengthSubstring("ccbcb");
} 