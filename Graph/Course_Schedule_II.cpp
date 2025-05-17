class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        vector<int> ans;
        queue<int> q;
        for (auto& i : edges) {
            int u = i[0];
            int v = i[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                int node = q.front();
                ans.push_back(node);
                q.pop();
                for (auto& j : adj[node]) {
                    indegree[j]--;
                    if (indegree[j] == 0) {
                        q.push(j);
                    }
                }
            }
        }
        return (ans.size() == V) ? ans : vector<int>();
    }
};