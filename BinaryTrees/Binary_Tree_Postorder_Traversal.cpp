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
        //     postorderTraversal(root->left);
        //     postorderTraversal(root->right);
        //     ans.push_back(root->val);
        // }
        vector<int> postorderTraversal(TreeNode* root) {
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
                if (node->left != NULL) {
                    st.push(node->left);
                }
                if (node->right != NULL) {
                    st.push(node->right);
                }
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };