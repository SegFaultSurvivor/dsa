class Solution {
  public:
   bool dfs(vector<vector<int>>& adj, vector<int>& vis, int node, int parent) {
        vis[node] = 1;
        for (auto& i : adj[node]) {
            if (vis[i] == 1 && i != parent) {
                return 1;
            }
            if (vis[i] == -1) {
                bool flag = dfs(adj, vis, i, node);
                if (flag == 1) {
                    return 1;
                }
            }
        }
        return 0;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> vis(V, -1);
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < V; i++) {
            if (vis[i] == -1) {
                if (dfs(adj, vis, i, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};