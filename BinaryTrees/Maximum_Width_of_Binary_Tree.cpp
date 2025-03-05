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
#define ll long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int maxi = INT_MIN;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int len = q.size();
            int start = q.front().second;
            int end = q.back().second;
            maxi = max(maxi, (end - start + 1));
            for (int i = 0; i < len; i++) {
                auto ptr = q.front();
                TreeNode* node = ptr.first;
                int index = ptr.second;
                q.pop();
                if (node->left) {
                    q.push({node->left, (ll)2 * index + 1});
                }
                if (node->right) {
                    q.push({node->right, (ll)2 * index + 2});
                }
            }
        }
        return maxi;
    }
};