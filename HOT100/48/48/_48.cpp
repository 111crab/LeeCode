#include<vector>
using namespace std;
class Solution {
    static constexpr int dirForRecord[4][2] = {{-1, 0},{0,1},{1,0},{0,-1}};
    static constexpr int dirForWrite[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    void rotate_self(vector<vector<int>>& matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int k = 0, i = m - 1 , j = 0, d = 0;
        vector<int> temp(n*m);
        for (k = 0; k < n * m; k++)
        {
            temp[k] = matrix[i][j];
            matrix[i][j] = INT_MAX;
            int x = i + dirForRecord[d][0];
            int y = j + dirForRecord[d][1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == INT_MAX)
            {
                d = (d + 1) % 4;
            }
            i = i + dirForRecord[d][0];
            j = j + dirForRecord[d][1];
        }
        i = 0;
        j = 0;
        d = 0;
        for (k = 0; k < n * m; k++)
        {
            matrix[i][j] = temp[k];
            int x = i + dirForWrite[d][0];
            int y = j + dirForWrite[d][1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] != INT_MAX)
            {
                d = (d + 1) % 4;
            }
            i = i + dirForWrite[d][0];
            j = j + dirForWrite[d][1];
        }
    }
    void rotate(vector<vector<int>>& matrix)
    {
        // 本题为 n * n 矩阵
        int n = matrix.size();
        // 转置
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 行翻转
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n/2 - 1; j++)
            {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};