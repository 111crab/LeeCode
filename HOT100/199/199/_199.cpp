#include <ios>
#include <vector>
#include <queue>
using namespace std;

class Solution {
     struct TreeNode {
             int val;
             TreeNode *left;
             TreeNode *right;
             TreeNode() : val(0), left(nullptr), right(nullptr) {}
             TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
             TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
         };
public:
    // 层序 bfs
    // 存入每层最后 pop 的节点（即为最右节点）
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                if (i == size - 1) ans.push_back(node->val);
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
    // dfs
    // 在先遍历右子树的前提下：若新到达了一层，则当前第一个到达的节点为本层的最右节点。
    vector<int> ans;
    void dfs(TreeNode* node, int deep){
        if (node == nullptr) return;
        if (deep == ans.size())
        {
            ans.push_back(node->val);
        }
        dfs(node->right, deep + 1);
        dfs(node->left, deep + 1);
    }
    vector<int> rightSideView_dfs(TreeNode* root) {
        if (root == nullptr) return {};
        dfs(root, 0);
        return ans;
    }
};