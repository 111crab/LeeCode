#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    // dfs(i,j) s1 的前 i 个字符 与 s2 的前 j 个字符，对齐所需要的最大操作数。
    // 函数入口从两个串的最末尾开始对齐。
    int dfs(string &s1, string &s2, vector<vector<int>> &mem, int i, int j)
    {
        // 如果某个字符串对齐完了(绞尽脑汁了)，只能通过删除另外一个字符串的剩余来对齐。
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;
        if (mem[i][j] != -1) return mem[i][j];
        
        // 当前相同，不需要操作，检查前面。
        if (s1[i] == s2[j]) return mem[i][j] = dfs(s1, s2, mem, i - 1, j - 1);
        // 改变 s1[i] 让它 = s2[j] 此时 op数 + 1,再递归对齐他两前面的子问题 
        int op_change = dfs(s1, s2, mem, i - 1, j - 1) + 1;
        // 直接把这个 s1[i] 删了，交给其前 i - 1 个来对齐，当然 op数 + 1
        int op_del = dfs(s1, s2, mem, i - 1, j) + 1;
        // 相当于在 s1[i] 后面插入一个 s2[j] 相同的字符（实际上没插入），新插入字符就和当前的 s2[j] 对齐完毕，op+1，下一组待对齐对象就是 s1(i) 和 s2(j - 1)
        int op_insert = dfs(s1 , s2, mem, i, j - 1) + 1;
        
        return mem[i][j] = min({op_change, op_del, op_insert});
    }
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> mem = vector<vector<int>>(501, vector<int>(501, -1));
        return dfs(word1, word2, mem, len1 - 1, len2 - 1);
    }
};