#include <vector>
#include <queue>
using namespace std;

class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int M = grid.size();
            int N = grid[0].size();
            
            int freshOranges = 0;
            queue<pair<int,int>> q;
            // 记录新鲜橘子的数量和[一开始]就是腐烂橘子的位置
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (grid[i][j] == 1) freshOranges++;
                    if (grid[i][j] == 2) 
                    {
                        q.push({i, j});
                    }
                }
            }
            // 没有新鲜的直接返回 0min
            if (freshOranges == 0) return 0;
            // BFS
            int time = 0;
            int dx[4] = {-1, 1, 0, 0};
            int dy[4] = {0, 0, -1, 1};
            while (freshOranges && !q.empty()) // 只有还剩余新鲜橘子的时候才走动 Time，不然传染完叶子节点后还有多走一次时间
            {
                time++;
                int size = q.size();
                
                for (int i = 0; i < size; i++)
                {
                    auto [r,c] = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nr = r + dx[k];
                        int nc = c + dy[k];
                        if (0 <= nr && nr < M && 0 <= nc && nc < N && grid[nr][nc] == 1)
                        {
                            freshOranges--;
                            grid[nr][nc] = 2;
                            q.push({nr, nc});
                        }
                    }
                }
            }
            return freshOranges ? -1 : time;
        }
    };