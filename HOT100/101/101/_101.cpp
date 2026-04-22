  struct TreeNode {
            int val;
          TreeNode *left;
          TreeNode *right;
          TreeNode() : val(0), left(nullptr), right(nullptr) {}
          TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
          TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };
class Solution {
public:
    bool CheckIsMirror(TreeNode *l, TreeNode *r)
    {
        if (!l && !r) return true;
        if (!l || !r || l->val != r->val) return false;
        return CheckIsMirror(l->left, r->right) && CheckIsMirror(l->right, r->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return CheckIsMirror(root->left, root->right);
    }
};