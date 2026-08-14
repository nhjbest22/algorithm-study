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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root->left);
        Q.push(root -> right);

        while(!Q.empty()){
            auto l = Q.front(); Q.pop();
            auto r = Q.front(); Q.pop();

            if(!l && !r) continue;
            if(!l || !r) return false;
            if(l->val != r->val) return false;

            Q.push(l->left); Q.push(r->right);
            Q.push(l->right); Q.push(r->left);
        }

        return true;
    }
};