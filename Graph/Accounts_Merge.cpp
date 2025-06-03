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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int V = accounts.size();
        vector<int> parent(V, -1);
        vector<int> rank(V, 0);
        int index = 0;
        int flag = 0;
        unordered_map<string, int> mp1;
        unordered_map<int, vector<string>> mp2;
        vector<vector<string>> ans;
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
        for (auto& i : accounts) {
            flag = 0;
            for (auto& j : i) {
                if (flag == 0) {
                    flag = 1;
                    continue;
                }
                if (mp1.find(j) == mp1.end()) {
                    mp1[j] = index;
                } else {
                    int u_parent = find(mp1[j], parent);
                    int v_parent = find(index, parent);

                    if (u_parent != v_parent) {
                        Union(u_parent, v_parent, parent, rank);
                    }
                }
            }
            index++;
        }
        for (auto& i : mp1) {
            string res = i.first;
            int node = i.second;
            int p = find(node, parent);
            mp2[p].push_back(res);
        }
        for (auto& i : mp2) {
            vector<string> temp;
            int node = i.first;
            string name = accounts[node][0];
            vector<string> res = i.second;
            sort(res.begin(), res.end());
            temp.push_back(name);
            for (auto& j : res) {
                temp.push_back(j);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};