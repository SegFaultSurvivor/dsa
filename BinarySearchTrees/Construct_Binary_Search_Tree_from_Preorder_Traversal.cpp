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
        TreeNode* fun(vector<int>& preorder, vector<int>& inorder,
                      unordered_map<int, int>& mp, int& idx, int start, int end) {
    
            if (start > end) {
                return NULL;
            }
            int value = preorder[idx];
            TreeNode* temp = new TreeNode(value);
            idx++;
    
            int cur_idx = mp[value];
    
            temp->left = fun(preorder, inorder, mp, idx, start, cur_idx - 1);
            temp->right = fun(preorder, inorder, mp, idx, cur_idx + 1, end);
    
            return temp;
        }
        TreeNode* bstFromPreorder(vector<int>& preorder) {
            vector<int> inorder = preorder;
            sort(inorder.begin(), inorder.end());
            unordered_map<int, int> mp;
            int idx = 0;
            for (int i = 0; i < inorder.size(); i++) {
                mp[inorder[i]] = i;
            }
            TreeNode* root = fun(preorder, inorder, mp, idx, 0, inorder.size() - 1);
            return root;
        }
    };