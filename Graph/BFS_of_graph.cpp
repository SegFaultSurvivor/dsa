class Solution {
    public:
      vector<int> ans2;
      vector<int> bfs(vector<vector<int>> &adj) {
          int V = adj.size();
          queue<int> q;
          vector<int> vis(V, -1);
          q.push(0);
          vis[0] = 1;
          while (!q.empty()) {
              int len = q.size();
              for (int i = 0; i < len; i++) {
                  int node = q.front();
                  ans2.push_back(node);
                  q.pop();
                  for (auto& i : adj[node]) {
                      if (vis[i] == -1) {
                          q.push(i);
                          vis[i] = 1;
                      }
                  }
              }
          }
          return ans2;
      }
  };