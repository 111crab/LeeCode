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
#include <string.h>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
     struct ListNode {
             int val;
            ListNode *next;
             ListNode() : val(0), next(nullptr) {}
             ListNode(int x) : val(x), next(nullptr) {}
             ListNode(int x, ListNode *next) : val(x), next(next) {}
         };
    ListNode* reverseList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* rev_head = reverseList(head->next);
        ListNode* tail = head->next;
        tail->next = head;
        head->next = nullptr;
        return rev_head;
    }
    ListNode* FindMid(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // 用 string 记录 反转前 和 反转后 的整个列表， 对比是否相同
    bool isPalindrome(ListNode* head) {
        ListNode* H = head;
        vector<string> st1;
        while (H != nullptr)
        {
            st1.push_back(to_string(H->val));
            H = H->next;
        }
        ListNode* revHead = reverseList(head);
        vector<string> st2;
        while (revHead != nullptr)
        {
            st2.push_back(to_string(revHead->val));
            revHead = revHead->next;
        }
        if (st1 == st2) return true;
        else return false;
    }
    // 通过反转后半链表来比较
    bool isPalindrome_2(ListNode* head) {
        ListNode* mid = FindMid(head);
        ListNode* head2 = reverseList(mid);
        while (head2 != nullptr)
        {
            if (head2->val != head->val) return false;
            head2 = head2->next;
            head = head->next;
        }
        return true;
    }
};