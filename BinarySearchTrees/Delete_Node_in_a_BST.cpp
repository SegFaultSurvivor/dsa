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
        vector<pair<int, TreeNode*>> inorder;
        void inorder_traversal(TreeNode* root) {
            if (!root)
                return;
            inorder_traversal(root->left);
            inorder.push_back({root->val, root});
            inorder_traversal(root->right);
        }
        int predecessor(int key) {
            for (int i = 0; i < inorder.size(); i++) {
                if (key == inorder[i].first) {
                    return i - 1;
                }
            }
            return -1;
        }
        TreeNode* del(TreeNode* root, int key) {
            if (!root)
                return NULL;
    
            else if (root->val == key) {
                if (!root->left && !root->right) {
                    delete (root);
                    return NULL;
                } else if (root->left && !root->right) {
                    TreeNode* temp = root->left;
                    delete (root);
                    return temp;
                } else if (!root->left && root->right) {
                    TreeNode* temp = root->right;
                    delete (root);
                    return temp;
                } else {
                    int idx = predecessor(key);
                    int value = inorder[idx].first;
                    TreeNode* temp = inorder[idx].second;
                    root->val = value;
                    root->left = del(root->left, value);
                    return root;
                }
            } else if (root->val >= key) {
                root->left = del(root->left, key);
    
            } else {
                root->right = del(root->right, key);
            }
            return root;
        }
        TreeNode* deleteNode(TreeNode* root, int key) {
            if (!root)
                return NULL;
            inorder_traversal(root);
            TreeNode* ans = del(root, key);
            return ans;
        }
    };