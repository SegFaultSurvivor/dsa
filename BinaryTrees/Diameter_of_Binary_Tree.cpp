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
        int maxi = INT_MIN;
        int fun(TreeNode* root) {
            if (root == NULL) {
                return 0;
            }
            int leftSide = 1 + fun(root->left);
            int rightSide = 1 + fun(root->right);
            int value = (leftSide - 1) + (rightSide - 1);
            maxi = max(maxi, value);
            return max(leftSide, rightSide);
        }
        int diameterOfBinaryTree(TreeNode* root) {
            int ans = fun(root);
            return maxi;
        }
    };