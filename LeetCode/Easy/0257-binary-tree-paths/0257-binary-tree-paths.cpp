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
    void backtrack(TreeNode* cur, vector<string>& ans, string str){
        str += to_string(cur->val);
        if(cur->left == nullptr && cur->right == nullptr){
            ans.push_back(str);
            return;
        }

        if(cur -> left != nullptr) backtrack(cur -> left, ans, str + "->");
        if(cur -> right != nullptr) backtrack(cur->right, ans, str + "->");
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        backtrack(root, ans, "");

        return ans;
    }
};