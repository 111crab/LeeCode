/**
* Definition for a binary tree node.

 */
#include <vector>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(),inorder.end(),preorder[0]);
        int root_index_inorder = distance(inorder.begin(),it);
        
        // left
        vector<int> left_in(inorder.begin(), it);
        vector<int> left_pre(preorder.begin() + 1, preorder.begin() + 1 + left_in.size());
        root->left = buildTree(left_pre, left_in);
        
        // right
        vector<int> right_in(it + 1, inorder.end());
        vector<int> right_pre(preorder.begin() + 1 + left_in.size(),preorder.end());
        root->right = buildTree(right_pre, right_in);

        return root;
    }
};