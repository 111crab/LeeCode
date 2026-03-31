#include <algorithm>
#include <unordered_map>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> map;
        Node* curr = head;
        // 1. 先创建所有的新节点
        while (curr)
        {
            map[curr] = new Node(curr->val);
            curr = curr->next;
        }
        // 2. 再连线
        curr = head;
        Node* dummy = new Node(0);
        Node* rear = dummy;
        while (curr)
        {
            // 尾插法
            rear->next = map[curr];
            rear = rear->next;
            rear->next = map[curr->next];
            rear->random = map[curr->random];
            curr = curr->next;
        }
        rear->next = NULL;
        return dummy->next;
    }
};