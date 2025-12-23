#include <string>
#include <unordered_map>

class Solution {
public:
    int numberOfSubstrings(std::string s) {

        int ans  = 0;
        int left = 0;
        std::unordered_map<char , int> cnt;

        for (int right = 0; right < s.size(); right++)
        {
            char c = s[right];
            cnt[c]++;

            while(cnt['a'] >= 1 && cnt['b'] >= 1 && cnt['c'] >= 1)
            {
                cnt[s[left]]--;
                left++;
            }

            ans+= left;
        }
        return ans;
    }
};
