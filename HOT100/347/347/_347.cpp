#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // 堆排序：使用频率来建立小根堆
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int num :nums) map[num]++;
        priority_queue<pair<int ,int>, vector<pair<int,int>>, greater<pair<int ,int>>> minHeap;

        // map[num] = fre
        for (auto &it : map)
        {
            // 小根堆的维护一般默认 push 的第一个元素为基准，所以需要颠倒使用
            minHeap.push({it.second, it.first});
            if (minHeap.size() > k) minHeap.pop();
        }
        vector<int> ans;
        while (!minHeap.empty())
        {
            // 因为前面颠倒使用，其实 小根堆 每个节点对 的第二元素就是数字本身
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
    // 桶排序
    vector<int> topKFrequent_buckets(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        for (int num :nums) map[num]++;
        // n + 1 目的是为了让下标和频率对应上，因为频率最高就是 n （即为所有元素都是相同的）
        vector<vector<int>> buckets(n + 1);

        for (auto &it : map)
        {
            buckets[it.second].push_back(it.first);
        }

        vector<int> ans;
        for (int i = n; i >= 0; i --)
        {
            for (int num : buckets[i])
            {
                if (ans.size() == k) break;
                ans.push_back(num);
            }
        }
        return ans;
    }
};