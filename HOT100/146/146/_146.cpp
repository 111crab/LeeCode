#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
class LRUCache {
    struct Node
    {
        int key;
        int value;
        Node *next, *prev;
        Node(int k,int v) : key(k), value(v), next(NULL), prev(NULL) {}
    };
public:
    int count;
    int max;
    Node* dummy;
    Node* rear;
    unordered_map<int, Node*> mp;
    
    LRUCache(int capacity) {
        max = capacity;
        count = 0;
        dummy = new Node(0,0);
        rear = dummy;
    }
    void MoveToTail(Node *node)
    {
        // 若已经是结尾则直接返回
        if (node->next == NULL) return;
        // 1.从链表分离
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // 2.插入尾巴
        rear->next = node;
        node->prev = rear;
        node->next = nullptr;
        rear = node;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        MoveToTail(mp[key]);
        return mp[key]->value;
    }
    
    void put(int key, int value) {
        if (mp.find(key) == mp.end())
        {
           if (count < max)
           {
               Node* node = new Node(key, value);
               mp[key] = node;
               rear->next = node;
               node->prev = rear;
               rear = node;
               count++;
           }
           else
           {   // 1.删去头
               Node* removal = dummy->next;
               mp.erase(removal->key);
               // 如果删除的是最后一个节点，将 rear 移回 dummy
               if (rear == removal) rear = dummy;
               dummy->next = removal->next;
               // 若是通常节点，则别忘了指回去
               if (removal->next) removal->next->prev = dummy;
               delete removal;
               
               // 2.在尾巴加
               Node* node = new Node(key, value);
               mp[key] = node;
               rear->next = node;
               node->prev = rear;
               rear = node;
           }
        }
        else
        {
            mp[key]->value = value;
            MoveToTail(mp[key]);
        }
    }
};
