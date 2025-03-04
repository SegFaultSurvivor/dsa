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
        map<int, vector<pair<int, int>>> mp;
        void fun(TreeNode* root, int col, int row) {
            if (!root)
                return;
            mp[col].push_back({row, root->val});
            fun(root->left, col - 1, row + 1);
            fun(root->right, col + 1, row + 1);
        }
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            vector<vector<int>> ans;
            fun(root, 0, 0);
            for (auto& i : mp) {
                vector<pair<int, int>> temp1;
                vector<int> temp2;
                for (auto& j : i.second) {
                    temp1.push_back(j);
                }
                if (temp1.size() > 1) {
                    sort(temp1.begin(), temp1.end(), [](auto& a, auto& b) {
                        if (a.first == b.first) {
                            return a.second < b.second;
                        }
                        return a.first < b.first;
                    });
                }
                for (auto& k : temp1) {
                    temp2.push_back(k.second);
                }
                ans.push_back(temp2);
            }
            return ans;
        }
    };