/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* cur, TreeNode* &p, TreeNode* &q){
        if(!cur || cur == p || cur == q) return cur;

        auto l = dfs(cur->left, p ,q);
        auto r = dfs(cur->right, p ,q);

        if(l && r) return cur;
        return l ? l : r;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};