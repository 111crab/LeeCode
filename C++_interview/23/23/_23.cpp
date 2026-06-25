#include <queue>
#include <vector>
using namespace std;
// LeetCode 定义的数据结构
class Solution {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
public:
    struct compare
    {
        bool operator()(const ListNode *a, const ListNode *b)
        {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for (auto& node : lists) if (node) pq.push(node);
        ListNode* ans = new ListNode(0);
        ListNode* rear = ans;
        while (!pq.empty())
        {
            ListNode* minNode = pq.top();
            pq.pop();
            rear->next = minNode;
            rear = rear->next;
            if (minNode->next) pq.push(minNode->next);
        }
        int a ;
        return ans->next;
    }
};