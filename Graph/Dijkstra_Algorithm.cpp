class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj (V);
        vector<int> dist (V,INT_MAX);
        for(auto& i : edges){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adj[u].push_back({wt,v});
        }
        dist[src] = 0;
        pq.push({0,src});
        while(!pq.empty()){
            int len = pq.size();
            for(int i=0;i<len;i++){
                auto data = pq.top();
                int distance = data.first;
                int node = data.second;
                pq.pop();
                for(auto& i : adj[node]){
                    if(dist[i.second] > i.first + distance){
                       dist[i.second] = i.first + distance;
                       pq.push({dist[i.second],i.second});
                    }
                }
            }
        }
        return dist;
    }
};