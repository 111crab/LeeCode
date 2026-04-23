#include <algorithm>

/**
 * Definition for a binary tree node.

 */
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
    int ans;
    int cur_index = 0;
    void find(TreeNode* root, int k, int index)
    {
        if (root == nullptr) return;
        find(root->left, k, cur_index);
        cur_index++;
        if (cur_index == k)
        {
            ans = root->val;
            return;
        }
        find(root->right, k, cur_index);
    }
    int kthSmallest(TreeNode* root, int k) {
        find(root, k, cur_index);
        return ans;
    }
};