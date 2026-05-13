class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n+1,n);
        f[0] = 0;
        for(int i = 1; i * i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(j >= i * i) f[j] = min(f[j], f[j - i * i] + 1);
            }
        }
        return f[n];
    }
};