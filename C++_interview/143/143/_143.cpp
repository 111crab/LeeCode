
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
public:

    ListNode* findLeftMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while (fast && fast->next)
        {
            slow = slow ->next;
            fast = fast->next ->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head)
    {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while (cur != nullptr)
        {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {

        if (!head || !head->next) return;
        
        ListNode* leftMid = findLeftMid(head);
        ListNode* rightPart = leftMid->next;
        leftMid->next = nullptr;

        rightPart = reverse(rightPart);
        
        ListNode* cur_1 = head; 
        ListNode* cur_2 = rightPart;

        while (cur_2 != nullptr)
        {
            ListNode* nxt1 = cur_1->next;
            ListNode* nxt2 = cur_2->next;
            
            cur_1->next = cur_2;
            cur_2->next = nxt1;

            cur_1 = nxt1;
            cur_2 = nxt2;
            
        }
        
    }
};