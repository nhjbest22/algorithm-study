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

    // r 보다 작으면서, l 보다는 커야함
    bool dfs(TreeNode *cur, long long l, long long r){
        if(!cur) return true;

        if(l >= cur->val || r <= cur->val) return false;

        return dfs(cur->left, l, cur->val) && dfs(cur->right, cur->val, r);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, INT64_MIN, INT64_MAX);
    }
};