struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *L = new ListNode(0,head); // a new dummy node
        ListNode *tmp = L; // represent this [tmp]'s next and next->next which is going to exchange  
        while (!tmp->next && !tmp->next->next)
        {
            // 1. Recording the node1 and node2 which is going to exchange the position
            ListNode *n1 = tmp->next;
            ListNode *n2 = n1->next;
            // 2. exchange for n1 and n2
            tmp->next = n2;
            n1->next = n2->next;
            n2->next = n1;
            // 3. reset the tmp
            tmp = n1;
        }
        return L->next;
    }
};