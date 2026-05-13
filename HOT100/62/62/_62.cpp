#include <vector>
using namespace std;
class Solution {
public:
    int dfs(int m, int n, int i, int j, vector<vector<int>> &mem)
    {
        if (i < 0 || i >= m || j < 0 || j >= n) return 0;
        if (i == m - 1 && j == n - 1) return mem[i][j] = 1;
        if (mem[i][j] != -1) return mem[i][j];
        int res_right = dfs(m, n, i, j + 1, mem);
        int res_down = dfs(m, n , i + 1, j ,mem);

        return mem[i][j] = res_right + res_down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> mem(101, vector<int>(101, -1));
        dfs(m, n, 0, 0, mem);
        return mem[0][0];
    }
};