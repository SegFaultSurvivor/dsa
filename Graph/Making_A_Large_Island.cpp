class Solution {
public:
    int find(int node, vector<int>& parent) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find(parent[node], parent);
    }
    void Union(int u, int v, vector<int>& parent, vector<int>& Size) {
        if (Size[u] > Size[v]) {
            parent[v] = u;
            Size[u] += Size[v];
        } else if (Size[u] < Size[v]) {
            parent[u] = v;
            Size[v] += Size[u];
        } else {
            parent[v] = u;
            Size[u] += Size[v];
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int V = m * n;
        vector<int> parent(V, -1);
        vector<int> Size(V, 1);
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (auto& k : dir) {
                        int row = i + k.first;
                        int col = j + k.second;
                        if (row >= 0 && row < m && col >= 0 && col < n &&
                            grid[row][col] == 1) {
                            int u = (i * n) + j;
                            int v = (row * n) + col;

                            int u_parent = find(u, parent);
                            int v_parent = find(v, parent);

                            if (u_parent != v_parent) {
                                Union(u_parent, v_parent, parent, Size);
                            }
                        }
                    }
                }
            }
        }
        int maxi = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> st;
                    int sum = 1;
                    for (auto& k : dir) {
                        int row = i + k.first;
                        int col = j + k.second;
                        if (row >= 0 && row < m && col >= 0 && col < n &&
                            grid[row][col] == 1) {

                            int v = (row * n) + col;

                            int v_parent = find(v, parent);
                            st.insert(v_parent);
                        }
                    }
                    for (auto& l : st) {
                        sum += Size[l];
                    }
                    maxi = max(maxi, sum);
                }
            }
        }
        return (maxi == 0) ? V : maxi;
    }
};