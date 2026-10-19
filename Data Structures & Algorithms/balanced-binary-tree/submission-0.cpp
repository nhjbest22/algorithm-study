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
    bool ans;

    int dfs(TreeNode* cur){
        if(!cur) return 0;

        int l = dfs(cur->left);
        int r = dfs(cur->right);

        ans *= abs(l-r) <= 1;

        return max(l, r) + 1;
    }

    bool isBalanced(TreeNode* root) {
        ans = true;

        dfs(root);
        return ans;
    }
};
