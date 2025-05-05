class Solution {
    public:
      vector<int> ans1;
      void dfs(int V, vector<vector<int>>& adj, vector<int>& vis, int node) {
          vis[node] = 1;
          ans1.push_back(node);
          for (auto& i : adj[node]) {
              if (vis[i] == -1) {
                  dfs(V, adj, vis, i);
              }
          }
      }
      vector<int> dfs(vector<vector<int>>& adj) {
          int V = adj.size();
          vector<int> vis(V, -1);
          dfs(V, adj, vis, 0);
          return ans1;
      }
  };