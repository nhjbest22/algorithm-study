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
    int target;
    unordered_map<long long, int> um;

    void dfs(TreeNode* cur, long long prefixSum){
        if(!cur) return;

        prefixSum += cur -> val;
        ans += um[prefixSum - target];

        um[prefixSum]++;
        dfs(cur->left, prefixSum);
        dfs(cur->right, prefixSum);
        um[prefixSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        um.clear(); um[0] = 1;
        target = targetSum;

        
        dfs(root, 0);
        
        return ans;
    }
};