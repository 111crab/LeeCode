#include <string>
using namespace std;

class Trie {
private:
    bool isEnd = false;
    Trie* nxt[26] = {nullptr};
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* cur = this;
        for (auto c : word)
        {
            if (cur->nxt[c - 'a'] == nullptr)
            {
                cur->nxt[c - 'a'] = new Trie();
            }
            cur = cur->nxt[c - 'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        Trie* cur = this;
        for (auto c : word)
        {
            if (cur->nxt[c - 'a'] == nullptr) return false;
            cur = cur->nxt[c - 'a'];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* cur = this;
        for (auto c : prefix)
        {
            if (cur->nxt[c - 'a'] == nullptr) return false;
            cur = cur->nxt[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */