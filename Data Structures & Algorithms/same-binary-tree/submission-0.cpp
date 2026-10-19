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
    
    void dfs(TreeNode* p, TreeNode* q){
        if(!ans) return;

        if((p && !q) || (!p && q)){
            ans = false;
            return;
        }

        if(!p && !q) return;

        ans *= (p->val == q->val);

        dfs(p->left, q->left);
        dfs(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        ans = true;

        dfs(p, q);
        return ans;
    }
};
