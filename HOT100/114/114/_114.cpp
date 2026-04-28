#include <algorithm>
#include <ios>
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
    TreeNode* last = nullptr;

    // 头插法
    void dfs(TreeNode *root)
    {
        if (root == nullptr) return;
        
        dfs(root->right);
        dfs(root->left);

        root->right = last;
        root->left = nullptr;
        last = root;
    }
    
    void flatten(TreeNode* root)
    {
        dfs(root);
    }
};``