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
        vector<int> rightSideView(TreeNode* root) {
            if (!root)
                return {};
            vector<int> ans;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                int len = q.size();
                vector<int> temp;
                for (int i = 0; i < len; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                    temp.push_back(node->val);
                }
                ans.push_back(temp[temp.size() - 1]);
            }
            return ans;
        }
    };