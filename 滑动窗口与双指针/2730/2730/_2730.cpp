#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSemiRepetitiveSubstring(std::string s) {
        int ans = -1 , left = 0;
        int len = s.length();
        int index = 0;
        if (len == 1)  return 1;
        vector<int> flag(len, 0); 
        for (int i = 0; i < len; i++)
        {
            if (i > 0 && s[i] == s[i - 1] )
            {
                index++;
                flag[i-1] = 1;
            }
            while (index > 1)
            {
                if (flag[left] == 1)
                {
                    index--;
                    flag[left] = 0;
                }
                left++;
            }

            ans = std::max(ans , i - left + 1);
        }
        return ans;
    }
};
