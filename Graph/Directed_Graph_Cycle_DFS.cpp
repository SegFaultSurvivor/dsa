class Solution {
  public:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& path, int node) {
        vis[node] = 1;
        path[node] = 1;
        for (auto& i : adj[node]) {
            if (vis[i] == 1 && path[i] == 1) {
                return 1;
            }
            if (vis[i] == -1) {
                bool flag = dfs(adj, vis, path, i);
                if (flag == 1) {
                    return 1;
                }
            }
        }
        path[node] = -1;
        return 0;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> vis (V,-1);
        vector<int> path (V,-1);
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        for (int i = 0; i < V; i++) {
            if (vis[i] == -1) {
                if (dfs(adj, vis, path, i)) {
                    return true;
                }
            }
        }
        return false;
    }
};