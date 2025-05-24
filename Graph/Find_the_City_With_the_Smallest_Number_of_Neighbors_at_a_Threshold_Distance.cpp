class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int>(n, INT_MAX));
        int res = 0, ans = INT_MAX;
        for (auto& i : edges) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adj[u][v] = wt;
            adj[v][u] = wt;
        }
        for (int i = 0; i < n; i++) {
            adj[i][i] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < adj.size(); j++) {
                for (int k = 0; k < adj.size(); k++) {
                    if (adj[j][i] != INT_MAX && adj[i][k] != INT_MAX) {
                        adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (adj[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= ans) {
                res = i;
                ans = count;
            }
        }
        return res;
    }
};
