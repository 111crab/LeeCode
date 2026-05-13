#include <vector>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>> &grid, int m, int n, int i, int j, vector<vector<int>> &mem)
    {
        if (i < 0 || i >= m || j < 0 || j >= n) return INT_MAX;
        if (mem[i][j] != -1) return mem[i][j];
        if (i == m - 1 && j == n - 1) return mem[i][j] = grid[i][j];

        int res_right = dfs(grid, m ,n, i, j + 1, mem);
        int res_down = dfs(grid, m ,n, i + 1, j,mem);

        return mem[i][j] = grid[i][j] + min(res_right, res_down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return grid[0][0];
        vector<vector<int>> mem(201, vector<int>(201, -1));
        dfs(grid, m , n, 0, 0, mem);
        return mem[0][0];
    }
};