class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V = adj.size();
        vector<int> dist (V,-1);
        queue<pair<int,int>> q;
        q.push({src,0});
        dist[src] = 0;
        while(!q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                auto ans = q.front();
                q.pop();
                int node = ans.first;
                int distance = ans.second;
                for(auto& i: adj[node]){
                    if(dist[i] == -1){
                        dist[i] = distance+1;
                        q.push({i,dist[i]});
                    }
                }
            }
        }
        return dist;
    }
};