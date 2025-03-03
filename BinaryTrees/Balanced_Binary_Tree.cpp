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
        int flag = 1;
        int fun(TreeNode* root) {
            if (root == NULL) {
                return 0;
            }
            int leftSide = 1 + fun(root->left);
            int rightSide = 1 + fun(root->right);
            if (abs(leftSide - rightSide) > 1) {
                flag = 0;
            }
            return max(leftSide, rightSide);
        }
        bool isBalanced(TreeNode* root) {
            int ans = fun(root);
            return flag;
        }
    };