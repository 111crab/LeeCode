#include <vector>
#include <unordered_map>
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
    // 自顶向下 DFS，形式上以[上层]为起始，[下层]为终点。
    // 枚举以当前节点为终点的时候，前面有多少符合条件的前缀和 "（当前前缀和 - targetSum）= 符合要求的前缀和 "
    int dfs(TreeNode* root , int targetSum,long long cur_prefix , unordered_map<long long, int> &mp_prefix)
    {
        if (!root) return 0;

        int ans = 0;
        cur_prefix += root->val;
        if (mp_prefix.find(cur_prefix - targetSum) != mp_prefix.end())
        {
            ans += mp_prefix[cur_prefix - targetSum];
        }
        mp_prefix[cur_prefix]++;

        ans += dfs(root->left, targetSum, cur_prefix, mp_prefix);
        ans += dfs(root->right, targetSum, cur_prefix, mp_prefix);

        mp_prefix[cur_prefix]--;
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mp_prefix;
        mp_prefix[0] = 1;
        return  dfs(root,targetSum,0,mp_prefix);
    }
};