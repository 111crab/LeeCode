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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * p1 = l1;
        ListNode* p2 = l2;
        ListNode* ans = new ListNode(0);
        ListNode* rear = ans;
        int cur = 0;
        int next = 0;
        int add1 = 0, add2 = 0;
        while (p1 || p2 || cur)
        {
            add1 = p1 ? p1->val :0;
            add2 = p2 ? p2->val :0;
            int sum = add1 + add2 + cur;
            ListNode* tmp = new ListNode(sum % 10);
            rear->next = tmp;
            rear = rear->next;
            cur = sum >= 10 ? 1 : 0;
            if(p1) p1 = p1 ->next;
            if(p2) p2 = p2 ->next;
        }
        return ans->next;
    }
};