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
    int ans;

    void dfs(TreeNode* cur, vector<int>& v, int& targetSum){
        if(!cur) return;

        long long sum = 0;

        v.push_back(cur->val);
        for(int i = v.size()-1; i>= 0; i--){
            sum += v[i];

            if(sum == targetSum) ans++;
        }

        dfs(cur->left, v, targetSum);
        dfs(cur->right, v, targetSum);

        v.pop_back();
    }

    int pathSum(TreeNode* root, int targetSum) {
        ans = 0;

        vector<int> v;
        dfs(root, v, targetSum);
        return ans;
    }
};