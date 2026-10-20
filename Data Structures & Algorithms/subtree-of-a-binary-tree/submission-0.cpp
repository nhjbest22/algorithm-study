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

    bool find(TreeNode* a, TreeNode* b){
        if(!a && !b) return true;

        if(a && b && a-> val == b -> val){
            return find(a->left, b->left) * find(a->right, b->right);
        }

        return false;
    }

    void dfs(TreeNode* cur, TreeNode* subRoot){
        if(!cur || ans) return;

        if(cur->val == subRoot -> val){
            ans |= find(cur, subRoot);
        }

        dfs(cur->left, subRoot);
        dfs(cur->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        ans = false;

        dfs(root, subRoot);
        return ans;
    }
};
