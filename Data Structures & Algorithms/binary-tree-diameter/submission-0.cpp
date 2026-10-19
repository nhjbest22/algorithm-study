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
        if(!cur) return -1;

        int l = 1 + dfs(cur->left);
        int r = 1 + dfs(cur->right);
        
        ans = max(ans, l + r);

        return max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        
        dfs(root);

        return ans;
    }
};
