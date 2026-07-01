
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}};

class Solution {
public:
    ListNode* findLeftMidNode(ListNode* head)
    {
        ListNode *fast = head->next;
        ListNode *slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode *cur = head;
        ListNode *prev = nullptr;

        while (cur)
        {
            ListNode *nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        
        ListNode*  leftMidNode = findLeftMidNode(head);
        ListNode* rightPart = reverseList(leftMidNode->next);

        ListNode* p = head;
        ListNode* q = rightPart;

        while (q)
        {
            if (p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }

        return true;
    }
};