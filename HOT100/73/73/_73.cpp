#include <vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool zeroHang = false;
        bool zeroLie = false;
        // 遍历列
        for (int k = 0; k < n; k++)
        {
            if (matrix[0][k] == 0) zeroHang = true;
        }
        // 遍历行
        for(int k = 0; k < m; k++)
        {
            if (matrix[k][0] == 0) zeroLie = true;
        }
        // 打标记，把第一行第一列当做标记本
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // 修改矩阵内元素
        for (int j = 1; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                for (int i = 1; i < m; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 1; j < n; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        // 处理第一行，第一列
        if (zeroHang == true)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }
        if (zeroLie == true)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};