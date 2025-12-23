#include <string>
#include <unordered_map>

class Solution {
public:
    int numberOfSubstrings(std::string s, int k) {

        int ans =0;
        int left =0;
        std::unordered_map<char ,int> map;

        for (char right : s)
        {
            map[right]++;
            while (map[right] == k)
            {
                map[s[left++]]--;
            }
            ans += left;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.numberOfSubstrings(std::string("abacb"), 2);
}