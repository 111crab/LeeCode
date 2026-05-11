#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        for (auto& p : prerequisites)
        {
            int cur = p[0];
            int pre = p[1];
            adj[pre].push_back(cur); 
            indegree[cur]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0) q.push(i);
        }

        int classDone = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int curr = q.front();
                q.pop();
                classDone++;
                for (auto& p : adj[curr])
                {
                    indegree[p]--;
                    if (indegree[p] == 0) q.push(p);
                }
            }
        }
        return classDone == numCourses;
    }
};