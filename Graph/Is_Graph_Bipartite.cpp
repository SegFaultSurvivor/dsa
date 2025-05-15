class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, int node,
             int colour) {
        vis[node] = colour;
        for (auto& i : graph[node]) {
            if (vis[i] == colour) {
                return 0;
            }
            if (vis[i] == -1) {
                bool flag = dfs(graph, vis, i, !colour);
                if (flag == 0) {
                    return 0;
                }
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), -1);
        int j = 0;
        for (int i = 0; i < graph.size(); i++) {
            if (vis[i] == -1) {
                bool flag = dfs(graph, vis, i, 0);
                if (flag == 0) {
                    return 0;
                }
            }
        }
        return 1;
    }
};