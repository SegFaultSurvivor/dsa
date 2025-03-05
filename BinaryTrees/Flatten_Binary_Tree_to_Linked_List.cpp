/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    public:
        vector<int> ans;
        void fun(TreeNode* root) {
            if (!root)
                return;
            ans.push_back(root->val);
            fun(root->left);
            fun(root->right);
        }
        void flatten(TreeNode* root) {
            if (!root)
                return;
            fun(root);
            root->left = NULL;
            root->right = NULL;
            TreeNode* res = root;
            for (int i = 1; i < ans.size(); i++) {
                TreeNode* temp = new TreeNode(ans[i]);
                res->right = temp;
                res = temp;
            }
        }
    };