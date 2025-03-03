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
        // void fun(TreeNode* root) {
        //     if (root == NULL) {
        //         return;
        //     }
        //     ans.push_back(root->val);
        //     preorderTraversal(root->left);
        //     preorderTraversal(root->right);
        // }
        vector<int> preorderTraversal(TreeNode* root) {
            // fun(root);
            // return ans;
            if (root == NULL)
                return {};
            stack<TreeNode*> st;
            st.push(root);
            while (!st.empty()) {
                TreeNode* node = st.top();
                st.pop();
                ans.push_back(node->val);
                if (node->right != NULL) {
                    st.push(node->right);
                }
                if (node->left != NULL) {
                    st.push(node->left);
                }
            }
            return ans;
        }
    };