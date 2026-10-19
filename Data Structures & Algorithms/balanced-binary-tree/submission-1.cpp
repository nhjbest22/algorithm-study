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
    int dfs(TreeNode* cur){
        if(!cur) return 0;

        int l = dfs(cur->left);
        if(l < 0) return -1;

        int r = dfs(cur->right);
        if(r < 0) return -1;

        if(abs(l - r) > 1) return -1;
        
        return max(l, r) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root) >= 0;
    }
};
