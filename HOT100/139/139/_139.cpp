#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // 此题应当被[视为]背包问题的[排列], 这样才好保证切割的严词合缝。
    // [排列]问题：外层应当枚举背包容量。
    bool wordBreak(string s, vector<string>& wordDict)
    {
        int n = s.size();
        // dp[i]: 当前容量 i 下，这个完成的字符能否被合法切割（对于全集来说是前 i 个）。
        vector<bool> dp(n + 1, false);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        // 此题性质，需要空字符也能被组合
        dp[0] = true;
        
        // 枚举背包容量
        for (int i = 1; i <= n; ++i)
        {
            // 注：此处不是直接枚举[物品]
            // 而是枚举[当前容量 i ]下，前 j 个字符能否合法切割
            // [合法切割]: 在切割前 j 个字符后，切割之后剩余部分是否仍在字典（或者可拆分成字典的组合）
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};