class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int c = coins.size();
        vector<int> f(amount+1,amount+1);
        f[0] = 0;
        for(int i = 0; i < c; ++i)
        {
            for(int j = 0; j <= amount; ++j)
            {
                if(j >= coins[i]) f[j] = min(f[j], f[j - coins[i]] + 1);
            }
        }
        int ans = f[amount];
        return ans > amount ? -1 : ans;
    }
};