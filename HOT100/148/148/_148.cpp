#include <algorithm>
#include <map>
#include <unordered_map>

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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* midNode = GetMidNode(head);
        ListNode* leftPart = head;
        ListNode* rightPart = midNode->next;
        midNode->next = nullptr;

        ListNode* left = sortList(leftPart);
        ListNode* right = sortList(rightPart);
        return merge(left, right);
    }
    
};