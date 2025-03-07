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
        void fun(TreeNode* root, vector<int>& ans) {
            if (!root)
                return;
            fun(root->left, ans);
            ans.push_back(root->val);
            fun(root->right, ans);
        }
        bool isValidBST(TreeNode* root) {
            vector<int> inorder;
            fun(root, inorder);
            for (int i = 0; i < inorder.size() - 1; i++) {
                if (inorder[i] >= inorder[i + 1]) {
                    return 0;
                }
            }
            return 1;
        }
    };