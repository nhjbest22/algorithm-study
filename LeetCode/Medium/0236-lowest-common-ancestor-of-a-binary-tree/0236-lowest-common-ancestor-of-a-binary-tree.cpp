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
    unordered_map<int, TreeNode*> um_par;
    unordered_map<int, int> um_height;

    void dfs(TreeNode* cur, TreeNode* pre, int height){
        if(!cur) return;

        um_par[cur->val] = pre;
        um_height[cur->val] = height;

        dfs(cur->left, cur, height + 1);
        dfs(cur->right, cur, height + 1);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        um_par.clear(); um_height.clear();

        dfs(root, root, 0);

        int l_h = um_height[p->val];
        int r_h = um_height[q->val];
        
        if(l_h < r_h){
            swap(p, q);
            swap(l_h, r_h);
        }

        while(l_h != r_h){
            p = um_par[p->val];
            l_h--;
        }

        while(p -> val != q->val){
            p = um_par[p->val];
            q = um_par[q->val];
        }

        return p;
    }
};