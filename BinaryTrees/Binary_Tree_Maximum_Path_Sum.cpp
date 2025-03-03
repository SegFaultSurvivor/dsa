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
            int leftSide = root->val + fun(root->left);
            int rightSide = root->val + fun(root->right);
            int value = leftSide + rightSide - root->val;
            maxi = max(maxi, value);
            return max({leftSide, rightSide, 0});
        }
        int maxPathSum(TreeNode* root) {
            int ans = fun(root);
            return maxi;
        }
    };