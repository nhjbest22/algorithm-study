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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int H = 0;
        vector<vector<int>> ans;
        vector<int> v[2'005];
        
        if(!root) return ans;

        queue<pair<TreeNode* ,int>> Q;
        Q.push({root, 0});

        while(!Q.empty()){
            auto [cur, height] = Q.front();
            Q.pop();

            H = max(H, height);
            v[height].push_back(cur->val);

            if(cur->left) Q.push({cur->left, height + 1});
            if(cur->right) Q.push({cur->right, height + 1});
        }

        for(int i = 1; i <= H; i+= 2){
            reverse(v[i].begin(), v[i].end());
        }

        for(int i = 0; i <= H; i++){
            ans.push_back(v[i]);
        }

        return ans;
    }
};