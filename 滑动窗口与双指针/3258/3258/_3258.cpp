#include <string>

class Solution {
public:
    int countKConstraintSubstrings(std::string s, int k) {
        int n = s.size();
        int ans = 0;
        int zeroCNT= 0;
        int oneCNT = 0;
        int left = 0;
        for (int right = 0; right < n; right++)
        {
            char c = s[right];
            if (c == '0') zeroCNT++;
            else oneCNT++;

            while (zeroCNT > k && oneCNT > k)
            {
                if (s[left] == '0') zeroCNT--;
                else oneCNT--;
            }

            ans += right - left + 1;
        }
        return ans;
    }
};
