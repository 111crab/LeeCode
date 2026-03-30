#include <vcruntime.h>
/**
* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
     struct ListNode {
             int val;
            ListNode *next;
             ListNode() : val(0), next(nullptr) {}
             ListNode(int x) : val(x), next(nullptr) {}
             ListNode(int x, ListNode *next) : val(x), next(next) {}
         };
    ListNode* reverse(ListNode* head)
    {
        ListNode *H = nullptr;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *nxt = curr->next;
            curr->next = H;
            H = curr;
            curr = nxt;
        }
        return H;
    }
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode *dummy = new ListNode(0,head);
        ListNode *rear = dummy;
        ListNode *pre = dummy;
        while (true)
        {
            // 1. 判断是否足够 k 个一组
            for (int i = 0 ; i < k; i++)
            {
                rear = rear->next;
                if (rear == nullptr) return dummy->next;
            }
            // 2. 记录
            ListNode* nextHead = rear->next; // 下组开头
            ListNode* start = pre->next; // 这组开头
            // 3. 翻转
            rear->next = nullptr; // 断开尾巴
            pre->next = reverse(start); // 翻转并且连接前组
            start->next = nextHead; // 连接下一组
            // 4.移动
            pre = start; // 记录当前末尾为下组末尾
            rear = pre; // rear 从这组末尾开始遍历
        }
    }
};