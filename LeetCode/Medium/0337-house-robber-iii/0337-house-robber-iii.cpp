/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> dfs(TreeNode* cur){
        if(!cur) return {0, 0};

        // robbed, not-robbed

        auto l = dfs(cur->left);
        auto r = dfs(cur->right);

        int rob = cur->val + l.second + r.second;
        int notRob = max(l.first, l.second) + max(r.first, r.second);

        return {rob, notRob};
    }

    int rob(TreeNode* root) {
        auto p = dfs(root);
        return max(p.first, p.second);
    }
};