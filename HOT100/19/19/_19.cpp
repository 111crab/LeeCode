/**
* Definition for singly-linked list.
 
 */
class Solution {
     struct ListNode {
             int val;
             ListNode *next;
             ListNode() : val(0), next(nullptr) {}
             ListNode(int x) : val(x), next(nullptr) {}
             ListNode(int x, ListNode *next) : val(x), next(next) {}
         };
public:
    // 方法-1. 一次遍历计数，二次遍历删除
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sum = 0;
        ListNode *dummy = new ListNode(0,head);
        ListNode* p = head;
        while (p)
        {
            p = p->next;
            sum++;
        }
        if (sum == 1) return nullptr;
        p = dummy;
        int count = 0;
        int target = sum - n;
        while (count <= target)
        {
            if (count == target)
            {
                ListNode* removel = p->next;
                p->next = removel->next;
                delete removel;
                break;
            }
            p = p -> next;
            count++;
        }
        return dummy->next;
    }
    // 方法-2. 遍历入栈，第 n 个出栈的节点为待删节点，而此时栈顶为其前驱
    // 方法-3. 双指针，快指针 与 慢指针相差 n 步，同速度遍历，当快指针走到末尾 null ，慢指针正好就是待删节点。（若慢指针从哨兵节点开始走，则会正好指向待删前驱节点）
    ListNode* removeNthFromEnd_3(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* f = head;
        ListNode* s = dummy;
        while (f)
        {
            if (n != 0)
            {
                f = f -> next;
                n--;
            }
            else
            {
                f = f->next;
                s = s->next;
            }
        }
        ListNode* removel = s->next;
        s->next = s->next->next;
        delete removel;
        return dummy->next;
    }
};

int main()
{
   
}