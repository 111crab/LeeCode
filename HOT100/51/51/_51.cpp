#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    bool IsValid(vector<string>& board, int r, int c)
    {
        for (int i = 0; i <= r; i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'Q' && i + j == r + c) return false;
                if (board[i][j] == 'Q' && i - j == r - c) return false;
             }
        }
        return true;
    }
    
    void dfs(vector<string>& board, int row, vector<bool>& used_col, int n)
    {
        if (row == n)
        {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if (IsValid(board, row, j) && used_col[j] == false)
            {
                board[row][j] = 'Q';
                used_col[j] = true;
                dfs(board, row + 1, used_col,n);
                board[row][j] = '.';
                used_col[j] = false;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<bool> used_col(n,false);
        dfs(board, 0, used_col, n);
        return ans;
    }
};