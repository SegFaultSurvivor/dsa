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
    void fun(TreeNode* root, vector<int>& ans) {
        if (!root)
            return;
        fun(root->left, ans);
        ans.push_back(root->val);
        fun(root->right, ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        fun(root, ans);
        int l = 0, r = ans.size() - 1;
        ll sum = 0;
        while (l < r) {
            sum = ans[l] + ans[r];
            if (sum == k) {
                return 1;
            } else if (sum < k) {
                l++;
            } else {
                r--;
            }
        }
        return 0;
    }
};