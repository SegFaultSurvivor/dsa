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
        TreeNode* fun(vector<int>& postorder, vector<int>& inorder,
                      unordered_map<int, int>& mp, int& idx, int start, int end) {
    
            if (start > end) {
                return NULL;
            }
            int value = postorder[idx];
            TreeNode* temp = new TreeNode(value);
            idx--;
    
            int cur_idx = mp[value];
    
            temp->right = fun(postorder, inorder, mp, idx, cur_idx + 1, end);
            temp->left = fun(postorder, inorder, mp, idx, start, cur_idx - 1);
    
            return temp;
        }
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            unordered_map<int, int> mp;
            int idx = postorder.size() - 1;
            for (int i = 0; i < inorder.size(); i++) {
                mp[inorder[i]] = i;
            }
            TreeNode* root =
                fun(postorder, inorder, mp, idx, 0, inorder.size() - 1);
            return root;
        }
    };