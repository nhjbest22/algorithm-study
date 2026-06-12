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
    vector<string> ans;
    int path[105];

    void backtrack(TreeNode* cur, int cnt){
        path[cnt] = cur->val;

        if(cur -> left == nullptr && cur -> right == nullptr){
            string str = to_string(path[0]);

            for(int i = 1; i <= cnt; i++){
                str += "->";
                str += to_string(path[i]);
            }
            ans.push_back(str);
            return;
        }

        if(cur -> left != nullptr) backtrack(cur -> left, cnt+1);
        if(cur -> right != nullptr) backtrack(cur->right, cnt+1);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        ans.clear();

        backtrack(root, 0);

        return ans;
    }
};