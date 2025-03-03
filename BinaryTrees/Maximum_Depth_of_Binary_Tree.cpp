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
        int fun(TreeNode* root) {
            if (root == NULL) {
                return 0;
            }
            int leftSide = 1 + fun(root->left);
            int rightSide = 1 + fun(root->right);
            return max(leftSide, rightSide);
        }
        int maxDepth(TreeNode* root) {
            int ans = fun(root);
            return ans;
        }
    };