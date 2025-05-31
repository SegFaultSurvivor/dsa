class Solution {
public:
    int find(int node, vector<int>& parent) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find(parent[node], parent);
    }
    void Union(int u, int v, vector<int>& parent, vector<int>& rank) {
        if (rank[u] > rank[v]) {
            parent[v] = u;
        } else if (rank[u] < rank[v]) {
            parent[u] = v;
        } else {
            parent[v] = u;
            rank[u] += 1;
        }
    }
    void fun(int V, vector<vector<int>>& edges, vector<int>& parent,
             vector<int>& rank) {
        for (auto& i : edges) {
            int u = i[0];
            int v = i[1];

            int u_parent = find(u, parent);
            int v_parent = find(v, parent);

            if (u_parent != v_parent) {
                Union(u_parent, v_parent, parent, rank);
            }
        }
    }
    int makeConnected(int V, vector<vector<int>>& edges) {
        if (edges.size() < V - 1) {
            return -1;
        }
        vector<int> parent(V, -1);
        vector<int> rank(V, 0);
        unordered_set<int> st;
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
        fun(V, edges, parent, rank);
        for (int i = 0; i < V; i++) {
            st.insert(find(i, parent));
        }
        return st.size() - 1;
    }
};