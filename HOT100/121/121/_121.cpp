#include <vector>
using namespace std;
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> pre_min(n, 0);
        pre_min[0] = prices[0];
        for (int i = 1; i < n; i++)
        {
            pre_min[i] = min(pre_min[i - 1], prices[i]);
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            ans = max(ans , prices[i] - pre_min[i]);
        }
        return ans;
    }
};