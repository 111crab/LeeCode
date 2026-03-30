#include <algorithm>
using namespace std;

class Solution {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }

        ListNode *pA = headA, *pB = headB;

        while (pA != pB)
        {
            if (pA == nullptr && pB == nullptr) return nullptr;
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }

        return pA;
    }
};