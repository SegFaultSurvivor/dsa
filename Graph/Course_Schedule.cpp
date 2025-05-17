class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int node, vector<int>& vis,
             vector<int>& path) {
        vis[node] = 1;
        path[node] = 1;
        for (auto& i : adj[node]) {
            if (vis[i] == 1 && path[i] == 1) {
                return 0;
            }
            if (vis[i] == -1) {
                bool flag = dfs(adj, i, vis, path);
                if (flag == 0) {
                    return 0;
                }
            }
        }
        path[node] = -1;
        return 1;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, -1);
        vector<int> path(numCourses, -1);
        for (auto& i : prerequisites) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
        }
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == -1) {
                bool ans = dfs(adj, i, vis, path);
                if (ans == 0) {
                    return 0;
                }
            }
        }
        return 1;
    }
};
