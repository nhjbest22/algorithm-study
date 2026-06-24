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
    void dfs(TreeNode* cur, vector<int>& inorder, vector<int>& postorder, int inorder_left, int postorder_left, int size){
        int root_val = postorder[postorder_left + size - 1];

        cur -> val = root_val;

        int left_cnt = 0;
        for(int i = inorder_left; i < inorder_left + size; i++){
            if(inorder[i] == root_val) break;

            left_cnt++;
        }

        int right_cnt = size - left_cnt - 1;

        if(left_cnt){
            cur->left = new TreeNode();
            dfs(cur->left, inorder, postorder, inorder_left, postorder_left, left_cnt);
        }

        if(right_cnt){
            cur->right = new TreeNode();
            dfs(cur->right, inorder, postorder, inorder_left + left_cnt + 1, postorder_left + left_cnt, right_cnt);
        }
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // inorder = left -> root -> right
        // postorder = left -> right -> root

        TreeNode* root = new TreeNode();
        dfs(root, inorder, postorder, 0, 0, inorder.size());

        return root;
    }
};