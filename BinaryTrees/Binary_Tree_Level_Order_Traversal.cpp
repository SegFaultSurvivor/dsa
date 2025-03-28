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
        vector<vector<int>> levelOrder(TreeNode* root) {
            if (!root)
                return {};
            queue<TreeNode*> q;
            vector<vector<int>> ans;
            q.push(root);
            while (!q.empty()) {
                vector<int> temp;
                int len = q.size();
                for (int i = 0; i < len; i++) {
                    TreeNode* node = q.front();
                    if (node->left != NULL) {
                        q.push(node->left);
                    }
                    if (node->right != NULL) {
                        q.push(node->right);
                    }
                    temp.push_back(node->val);
                    q.pop();
                }
                ans.push_back(temp);
            }
            return ans;
        }
    };