class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& path,
             int node) {
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
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, -1);
        vector<int> path(V, -1);
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (vis[i] == -1) {
                dfs(adj, vis, path, i);
            }
        }
        for (int i = 0; i < V; i++) {
            if (path[i] == -1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};