#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int cur_level_size = q.size();
            vector<int> current_level_ans;
      
            for (int i = 0; i < cur_level_size; i++)
            {
                TreeNode* n = q.front();
                q.pop();
                current_level_ans.push_back(n->val);
                if (n->left != nullptr) q.push(n->left);
                if (n->right != nullptr) q.push(n->right);
            }
            ans.push_back(current_level_ans);
        }
        return ans;
    }
};