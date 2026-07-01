
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    
    int getSize(ListNode* head)
    {
        int size = 1;
        ListNode* temp = head;

        while(temp -> next != nullptr)
        {
            temp = temp->next;
            ++size;
        }
        
        return size;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) return head;
        int n = getSize(head);
        int flag = n - (k % n);
        if (flag == n) return head;
        ListNode *p = head;
        while (flag > 1)
        {
            p = p->next;
            flag--;
        }
        ListNode *tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }

        ListNode *rightPart = p->next;
        p->next = nullptr;
        tail->next = head;
        
        return rightPart;
    }
};