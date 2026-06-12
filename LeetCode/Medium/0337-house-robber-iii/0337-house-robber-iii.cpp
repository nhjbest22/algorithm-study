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
    int dp[10'005][2];
    unordered_map<TreeNode*, int> um;
    int cnt;

    int dfs(TreeNode* cur, bool isRobbed){
        int idx = um[cur];
        if(dp[idx][isRobbed] != -1) return dp[idx][isRobbed];

        dp[idx][isRobbed] = isRobbed ? cur->val : 0;

        // if(cur->left != nullptr){
        //     dp[idx][isRobbed] += max(dfs(ur->left, false), dfs(cur->left, true));
        // }

        // if(cur->right != nullptr){
        //     dp[idx][isRobbed] += max(dfs(ur->right, false), dfs(cur->right, true));
        // }

        for(auto nxt: {cur->left, cur->right}){
            if(nxt == nullptr) continue;

            int MAX = dfs(nxt, false);
            if(isRobbed == false) MAX = max(MAX, dfs(nxt, true));

            dp[idx][isRobbed] += MAX;
        }

        return dp[idx][isRobbed];
    }

    void search_tree(TreeNode* cur){
        um[cur] = cnt++;

        if(cur->left != nullptr) search_tree(cur->left);
        if(cur->right != nullptr) search_tree(cur->right);
    }

    int rob(TreeNode* root) {
        fill(&dp[0][0], &dp[0][0] + 10'005*2, -1);
        um.clear();
        cnt = 0;

        search_tree(root);
        dfs(root, false);
        dfs(root, true);

        return max(dp[0][false], dp[0][true]);
    }
};