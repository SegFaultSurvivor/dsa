class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node,
             stack<int>& st) {
        vis[node] = 1;
        for (auto& i : adj[node]) {
            if (vis[i] == -1) {
                dfs(adj, vis, i, st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> vis(V, -1);
        stack<int> st;
        vector<int> ans;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        for (int i = 0; i < V; i++) {
            if (vis[i] == -1) {
                dfs(adj, vis, i, st);
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }    
};