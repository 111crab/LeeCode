
 
#include <regex>

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
    // 1。自顶向下检查法
    // 检查当前节点是否为 [min_val,max_val] 中，此为父节点的约束。
    bool check(TreeNode* root, long long min_val, long long max_val)
    {
        // 如果为空节点，不影响结果
        if (root == nullptr) return true;
        // 如果不在父节点约束内，则否
        if (root->val <= min_val || root->val >= max_val) return false;
        // 检查左右检点，并且更新其边界
        return check(root->left, min_val, root->val) && check(root->right, root->val, max_val);
    }
    bool isValidBST(TreeNode* root) {
        
        return check(root, LLONG_MIN, LLONG_MAX);
    }
    // 2.中序遍历出来的序列一定是个升序才对，可以记录上一个检查值，来和当前 root 比较，来判断是否符合 bst
};
