#include <algorithm>
#include <regex>

class Solution {
     struct TreeNode
     {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
public:
    TreeNode *ans = nullptr;
    // DFS 返回的是当前 root 包含了几个[符合要求的节点]
    int dfs(TreeNode* root ,TreeNode* p, TreeNode* q)
    {
        if (!root) return 0;
        int left_count = dfs(root->left,p, q);
        int right_count = dfs(root->right,p, q);
        int involved = 0;
        if (root->val == p->val || root->val == q->val) involved++;
        involved += left_count + right_count;
        if (involved == 2 && ans == nullptr)
        {
            ans = root;
        }
        return involved;
    }
    TreeNode* lowestCommonAncestor_self(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (p == root || q == root) return root;
        dfs(root,p,q);
        return ans;
    }

    // lowestCommonAncestor 返回的是公共节点的候选
    // a.如果某个 root 的 left 和 right 都能找到要求节点。那么这个节点就是最小的 LCA
    // b.如果不满足 a，则证明 p 和 q 为父子关系，先找到谁就直接返回就好了。
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root->val == p->val || root->val == q->val) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p ,q);
        TreeNode* right = lowestCommonAncestor(root->right, p ,q);

        if (left && right) return root;
        return left ? left : right;
    }
};
