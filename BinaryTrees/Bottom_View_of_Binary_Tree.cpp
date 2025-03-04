class Solution {
    public:
      map<int, pair<int, int>> mp;
      void fun(Node* root, int col, int row) {
          if (!root)
              return;
          if (mp.find(col) == mp.end()) {
              mp[col] = {row, root->data};
          } else {
              if (row >= mp[col].first) {
                  mp[col] = {row, root->data};
              }
          }
          fun(root->left, col - 1, row + 1);
          fun(root->right, col + 1, row + 1);
      }
      vector <int> bottomView(Node *root) {
          vector<int> ans;
          fun(root, 0, 0);
          for (auto& i : mp) {
              ans.push_back(i.second.second);
          }
          return ans;
      }
  };