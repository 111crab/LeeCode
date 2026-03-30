#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s;
        s.resize(n+1);
        for (int i = 0; i < nums.size(); i++)
        {
            s[i+1] = s[i] + nums[i];
        }
        int ans = 0;
        unordered_map<int, int> mp;
        for (int j = 0; j < s.size(); j++)
        {
            int match = s[j] - k;
            if (mp.find(match) != mp.end()) ans += mp[match];
            mp[s[j]]++;
        }
        return ans;
    }
};