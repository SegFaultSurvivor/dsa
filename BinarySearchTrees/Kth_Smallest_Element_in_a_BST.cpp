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
        priority_queue<int> pq;
        void fun(TreeNode* root, int& k) {
            if (!root) {
                return;
            }
            fun(root->left, k);
            pq.push(root->val);
            if (pq.size() > k) {
                pq.pop();
            }
            fun(root->right, k);
        }
        int kthSmallest(TreeNode* root, int k) {
            while (!pq.empty())
                pq.pop();
            fun(root, k);
            return pq.top();
        }
    };