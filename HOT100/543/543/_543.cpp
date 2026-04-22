#include <algorithm>
using namespace std;
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
    int ans = 0;
    
    int dfs(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int deep_left = dfs(root->left);
        int deep_right = dfs(root->right);
        ans = max(ans, deep_left + deep_right);
        return max(deep_left, deep_right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root);
        return ans;
    }
};