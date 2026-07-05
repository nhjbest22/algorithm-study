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
    vector<int> largestValues(TreeNode* root) {
        vector<int> MAX(100'005, INT32_MIN);
        int H = -1;

        queue<pair<TreeNode *, int>> Q;
        Q.push({root, 0});

        while(!Q.empty()){
            auto [cur, k] = Q.front();
            Q.pop();

            if(!cur) continue;

            MAX[k] = max(MAX[k], cur->val);
            H = k;

            Q.push({cur->left, k+1});
            Q.push({cur->right, k+1});
        }

        MAX.resize(H + 1);

        return MAX;
    }
};