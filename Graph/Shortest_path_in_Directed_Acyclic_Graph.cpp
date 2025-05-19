class Solution {
  public:
   void dfs(vector<vector<pair<int,int>>>& adj, int node, vector<int>& dist) {
        for (auto& neighbor : adj[node]) {
            if (dist[node] + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.first] = dist[node] + neighbor.second;
                dfs(adj, neighbor.first, dist);
            }
        }
    }
    void toposort(vector<vector<pair<int,int>>>& adj, int node,stack<int> &st,vector<int>& vis){
        vis[node] = 1;
        for (auto& i : adj[node]) {
            if (vis[i.first] == -1) {
                toposort(adj, i.first, st, vis);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<int> dist (V,INT_MAX/2);
        vector<int> vis (V,-1);
        vector<vector<pair<int,int>>> adj (V);
        stack<int> st;
        for(auto& i: edges){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adj[u].push_back({v,wt});
        }
        dist[0] = 0;
        //dfs(adj, 0, dist);
        toposort(adj,0,st,vis);
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto& i : adj[node]){
                if(dist[i.first] > dist[node] + i.second){
                    dist[i.first] = dist[node] + i.second;
                }
            }
        }
        for(int i=0;i<dist.size();i++){
            if(dist[i] == INT_MAX/2){
                dist[i] = -1;
            }
        }
        return dist;
    }
};