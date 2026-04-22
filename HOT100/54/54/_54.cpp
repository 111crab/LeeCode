#include <codecvt>
#include <vector>
using namespace std;
class Solution {
    static constexpr int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; 
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans(n * m,0);
        int i = 0, j = 0, d = 0;
        for (int k = 0; k < m * n; k++)
        {
            ans[k] = matrix[i][j];
            matrix[i][j] = INT_MAX;
            int x = i + dir[d][0];
            int y = j + dir[d][1];
            if (x < 0 || x >= m || y < 0 || y>= n || matrix[x][y] == INT_MAX)
            {
                d = (d + 1) % 4;
            }
            i = i + dir[d][0];
            j = j + dir[d][1];
        }
        return ans;
    }
    // 优化：不修改 matrix，其实可以不做标记，因为每次向右下左上的步数是可以计算的，并不需要额外的数组或者改变原来数组进行标记。
    // 类似每次横着走（左右），竖着走（上下），次与次之间所走步数都是递减 1 的
};