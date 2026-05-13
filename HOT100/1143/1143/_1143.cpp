#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int dfs(string &s1, string &s2, vector<vector<int>> &mem,int i, int j)
    {
        if (i < 0 || j < 0) return 0;
        if (mem[i][j] != -1) return mem[i][j];

        if (s1[i] == s2[j]) return mem[i][j] = 1 + dfs(s1, s2, mem, i - 1, j - 1);

        return mem[i][j] = max(dfs(s1, s2, mem, i - 1, j), dfs(s1, s2, mem, i, j - 1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        vector<vector<int>> mem(1001, vector<int>(1001, -1));
        dfs(text1, text2, mem, len1 - 1, len2 - 1);
        return mem[len1 - 1][len2 - 1];
    }
};