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

        
        int l = dfs(cur -> left);
        int r = dfs(cur -> right);

        // cout<<"cur: "<<cur->val<<endl;
        
        // cout<<"l: "<<l<<endl;
        // cout<<"r: "<<r<<endl;

        if(abs(l-r) > 1) ans = false;
        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        ans = true;
        dfs(root);
        
        return ans;
    }
};