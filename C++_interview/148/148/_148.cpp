


class Solution {
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
public:

    ListNode* findMid(ListNode* head)
    {
        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast && fast -> next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* tmp = dummy;
        ListNode* L1 = list1;
        ListNode* L2 = list2;
        while (L1 && L2)
        {
            if (L1 && L1->val <= L2->val)
            {
                tmp->next = L1;
                L1 = L1->next;
                tmp = tmp->next;
            }
            else
            {
                tmp->next = L2;
                L2 = L2->next;
                tmp = tmp->next;
            }
        }
        
        if (L1) tmp->next = L1;
        if (L2) tmp->next = L2;
        return dummy->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if (!head || !head -> next) return head;
        ListNode* mid = findMid(head);
        ListNode* List1 = head;
        ListNode* list2 = mid->next;
        mid->next = nullptr;

        ListNode* left = sortList(List1);
        ListNode* right =sortList(list2);

        ListNode* ans = merge(left, right);

        return ans;
    }
};