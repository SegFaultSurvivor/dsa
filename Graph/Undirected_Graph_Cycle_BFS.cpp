class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<pair<int, int>> q;
    vector<int> vis(V, -1);
    for (int i = 0; i < V; i++) {
        if (vis[i] == -1) {
            q.push({i, -1});
            vis[i] = 1;
            while (!q.empty()) {
                int len = q.size();
                for (int i = 0; i < len; i++) {
                    auto data = q.front();
                    int node = data.first;
                    int parent = data.second;
                    q.pop();
                    for (auto& i : adj[node]) {
                        if (vis[i] == 1 && i != parent) {
                            return 1;
                        }
                        if (vis[i] == -1) {
                            q.push({i, node});
                            vis[i] = 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
};