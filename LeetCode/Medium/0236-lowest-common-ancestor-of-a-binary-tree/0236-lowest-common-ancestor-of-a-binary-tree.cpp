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
    unordered_map<TreeNode*, TreeNode*> um_par;
    int l_h, r_h;

    void dfs(TreeNode* cur, TreeNode* pre, int height, TreeNode* p, TreeNode* q){
        if(!cur) return;

        um_par[cur] = pre;

        if(p == cur) l_h = height;
        if(q == cur) r_h = height;

        dfs(cur->left, cur, height + 1, p, q);
        dfs(cur->right, cur, height + 1, p, q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        um_par.clear();

        dfs(root, root, 0, p, q);

        if(l_h < r_h){
            swap(p, q);
            swap(l_h, r_h);
        }

        while(l_h != r_h){
            p = um_par[p];
            l_h--;
        }

        while(p != q){
            p = um_par[p];
            q = um_par[q];
        }

        return p;
    }
};