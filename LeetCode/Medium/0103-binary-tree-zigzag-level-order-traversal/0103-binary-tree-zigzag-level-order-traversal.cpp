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
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> Q;
        Q.push(root);
        bool lToR = true;

        while(!Q.empty()){
            int size = Q.size();
            vector<int> level;

            for(int i = 0; i < size; i++){
                auto cur = Q.front();
                Q.pop();

                level.push_back(cur->val);
                
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
            }

            if(!lToR) reverse(level.begin(), level.end());
            ans.push_back(level);
            lToR = !lToR;
        }

        return ans;
    }
};