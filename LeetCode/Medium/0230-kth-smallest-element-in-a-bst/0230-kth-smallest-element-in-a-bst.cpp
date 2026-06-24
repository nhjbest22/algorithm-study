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
    int ans = 0;

    int dfs(TreeNode* cur, int k){
        int cnt = 0;
        if(cur -> left) cnt += dfs(cur->left, k);

        cnt++;
        if(k == cnt) ans = cur->val;
        
        if(cur->right) cnt += dfs(cur->right, k - cnt);

        return cnt;
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);

        return ans;
    }
};