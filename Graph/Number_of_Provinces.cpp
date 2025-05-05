class Solution {
    public:
        void dfs(int V, vector<vector<int>>& isConnected, vector<int>& vis,
                 int node) {
            vis[node] = 1;
            int j = 0;
            for (auto& i : isConnected[node]) {
                if (isConnected[node][j] == 1 && vis[j] == -1) {
                    dfs(V, isConnected, vis, j);
                }
                j++;
            }
        }
        int findCircleNum(vector<vector<int>>& isConnected) {
            int V = isConnected.size();
            vector<int> vis(V, -1);
            int ans = 0;
            for (int i = 0; i < V; i++) {
                if (vis[i] == -1) {
                    dfs(V, isConnected, vis, i);
                    ans += 1;
                }
            }
            return ans;
        }
    };