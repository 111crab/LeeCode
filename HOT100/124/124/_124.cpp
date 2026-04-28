#include <algorithm>
using namespace std;

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
    // 注意路径的定义
    int ans = INT_MIN;
    int maxContribution(TreeNode* root)
    {
        if (!root) return 0;
        // 贡献为负数的话直接归 0
        int left = max(maxContribution(root->left), 0);
        int right = max(maxContribution(root->right),0);
        // 若本节点作为拐点，则最大贡献为？
        // 拐点意味着本节点父节点什么的都不能参与答案的计算，不然路径会重复
        int curr = root->val + left + right;
        ans = max(ans,curr);

        // 本节点的最大贡献 = 自己 + 左/右节点的非负贡献（若都为负数则，只传递自己，所加的子节点都是 0 而已）
        return root->val + max(left ,right);
    }
    // 该 root 的最大路径和
    int maxPathSum(TreeNode* root) {
        maxContribution(root);
        return ans;
    }
};