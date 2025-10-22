#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long origin_Profit = 0;
        long long sum = 0;
        long long ans = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            origin_Profit += prices[i] * strategy[i];   
        }
        ans = origin_Profit;
        sum = origin_Profit;
        for (int i = 0; i < prices.size(); i++)
        {
            int s = strategy[i];
            int p = prices[i];
            sum = sum + (1 - s) * p;

            if (i < k - 1)
            {
                if (i >= k/2 - 1) sum = sum - prices[i - k/2 + 1];
                continue;
            }

            ans = max(ans, sum);

            sum = sum + strategy[i - k + 1] * prices[i - k + 1] - prices[i + 1 - k/2];
            // 时刻注意滑动窗口永远是入之后才成立窗口大小，这时候再去更新answer
        }
        return ans;
    }
};