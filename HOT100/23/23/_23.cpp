#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
private:
    ListNode* GetMidNode(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* rear = dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                rear->next = l1;
                l1 = l1->next;  
            }
            else
            {
                rear->next = l2;
                l2 = l2->next;
            }
            rear = rear->next;
        }
        rear->next = l1 ? l1 : l2;
        return dummy->next;
    }
public:
    // 分治或者顺序合并 （分治也是两两合并，但是同时进行多次两个不同的两两合并）
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        ListNode* ans = lists[0];
        for (int i = 1; i < lists.size(); ++i)
        {
            ans = merge(ans, lists[i]);
        }
        return ans;
    }
    struct cmp
    {
        bool operator()(ListNode* a, ListNode* b) {return a->val > b->val;}
    };
    ListNode* mergeKLists_pq(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
      
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (auto node :lists) if (node) pq.push(node);

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
        rear->next = nullptr;
        return ans->next;
    }
};