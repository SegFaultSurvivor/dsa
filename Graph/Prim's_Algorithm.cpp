class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> graph[]) {
        vector<int> vis (V,-1);
        vector<int> parent (V,-1);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<pair<int,int>>> adj (V);
        int sum = 0;
        for(int i=0;i<V;i++){
            for(auto& j : graph[i]){
                int v = j[0];
                int wt = j[1];
                adj[i].push_back({v,wt});
                adj[v].push_back({i,wt});
            }
        }
        pq.push({0,0,-1});
        while(!pq.empty()){
            auto data = pq.top();
            pq.pop();
            int wt = data[0];
            int src = data[1];
            int cur_parent = data[2];
            if(vis[src] == 1){
                continue;
            }
            vis[src] = 1;
            parent[src] = cur_parent;
            sum+=wt;
            for(auto& i : adj[src]){
                if(vis[i.first] == -1){
                    pq.push({i.second,i.first,src});
                }
            }
        }
        return sum;
    }
};