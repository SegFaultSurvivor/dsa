class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int V, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<vector<pair<int, int>>> adj(V + 1);
        vector<int> dist(V + 1, INT_MAX);
        int maxi = -1;
        for (auto& i : times) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adj[u].push_back({wt, v});
        }
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            auto data = pq.top();
            int distance = data.first;
            int node = data.second;
            pq.pop();
            for (auto& i : adj[node]) {
                if (dist[i.second] > i.first + distance) {
                    dist[i.second] = i.first + distance;
                    pq.push({dist[i.second], i.second});
                }
            }
        }
        for (int i = 1; i < dist.size(); i++) {
            maxi = max(maxi, dist[i]);
        }
        return (maxi == INT_MAX) ? -1 : maxi;
    }
};