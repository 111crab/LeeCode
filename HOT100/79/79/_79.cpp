#include <atomic>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool ans = false;
    void dfs(vector<vector<char>>& board, string word, int i, int j, int index)
    {
        
        if (!(0 <= i && i < board.size() && 0 <= j && j < board[0].size()) || board[i][j] != word[index]) return;

        if (index == word.size() - 1)
        {
            ans = true;
            return;
        }
        
        char temp = board[i][j];
        board[i][j] = '0';
        dfs(board, word, i-1, j, index+1);
        dfs(board, word, i+1, j, index+1);
        dfs(board, word, i, j-1, index+1);
        dfs(board, word, i, j+1, index+1);
        board[i][j] = temp;   
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        for (int i = 0; i< board.size(); ++i)
        {
            for (int j = 0; j< board[0].size(); ++j)
            {
                dfs(board, word, i, j,0);
                if (ans == true) break;
            }
        }
        return ans;
    }
};