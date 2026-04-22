#include <vector>
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
    int dfs(TreeNode* root, int deep)
    {
        if (root == nullptr) return deep;
        int deep_left = dfs(root->left,deep);
        int deep_right = dfs(root->right,deep);
        deep = (deep_left > deep_right ? deep_left: deep_right) + 1;
        return deep;
    }
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int deep = 0;
        return dfs(root,deep);
    }
};