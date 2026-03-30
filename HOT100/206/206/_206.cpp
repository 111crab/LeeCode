

#include <vcruntime.h>

class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        // 1. 初始化两个指针
        ListNode* NewH = nullptr; // 想象这是新链表的“头”，初始为空
        ListNode* cur = head; // 这是当前正在处理的节点
        while (cur != nullptr)
        {
            // 2. 暂时存下当前节点的下一个，否则断开连接后就找不到了
            ListNode* nextTemp = cur->next;
            
            // 3. 核心反转动作：把当前节点的 next 指向“前一个”
            cur->next = NewH;
            
            // 4. 两个指针整体向后移动一位
            NewH = cur;
            cur = nextTemp;
        }
        // 5. 当 curr 为空时，prev 刚好指向原链表的最后一个节点，也就是新链表的头
        return NewH;
    }

    ListNode* reverseList_2(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* rev_head = reverseList_2(head->next);
        ListNode* tail = head->next;
        tail->next = head;
        head->next = nullptr;
        return rev_head;
    }
    
};
