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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> Q;

        if(root == nullptr) {
            return res;
        }
        
        vector<int> v;
        int prev_height = 0;

        Q.push({root, 0});

        while(!Q.empty()){
            auto [ptr, cur_height] = Q.front();
            Q.pop();

            if(prev_height != cur_height){
                prev_height = cur_height;
                res.push_back(v);
                v.clear();
            }
            v.push_back(ptr->val);

            if(ptr -> left != nullptr) Q.push({ptr -> left, cur_height + 1});
            if(ptr -> right != nullptr) Q.push({ptr -> right, cur_height + 1});
        }

        res.push_back(v);

        return res;
    }
};