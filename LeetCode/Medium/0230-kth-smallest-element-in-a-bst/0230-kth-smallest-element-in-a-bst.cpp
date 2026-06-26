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
    int ans = -1;
    int count = 0;

    void dfs(TreeNode* cur, int k){
        if(!cur || count >= k) return;

        dfs(cur->left, k);
        count++;

        if(count == k){
            ans = cur->val;
            return;
        }

        dfs(cur->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);

        return ans;
    }
};