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
        int fun(TreeNode* p, TreeNode* q) {
            if (!p && !q) {
                return 1;
            }
            if (p && !q || !p && q) {
                return 0;
            }
            if (p && q && p->val != q->val) {
                return 0;
            }
            int leftSide = fun(p->left, q->left);
            int rightSide = fun(p->right, q->right);
            return leftSide && rightSide;
        }
        bool isSameTree(TreeNode* p, TreeNode* q) {
            int ans = fun(p, q);
            return ans;
        }
    };