#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0,left = 0;
        int n = s.length();
        unordered_map<char, int> m;
        for (int right = 0; right < n; right++)
        {
            char c = s[right];
            m[c]++;

            while (m[c] > 1)
            {
                m[s[left]] --;
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};






int main()
{

    
}
