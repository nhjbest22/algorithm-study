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
    int ans;

    int dfs(TreeNode* cur){
        if(!cur) return 0;

        int l = dfs(cur -> left);
        int r = dfs(cur->right);

        ans = max(ans, l + r);

        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;

        dfs(root);
        return ans;
    }
};