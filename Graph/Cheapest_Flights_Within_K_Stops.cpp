class Solution {
public:
    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<vector<pair<int, int>>> adj(V);
        vector<int> dist(V, INT_MAX);
        for (auto& i : flights) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adj[u].push_back({wt, v});
        }
        dist[src] = 0;
        pq.push({0, {0, src}});
        while (!pq.empty()) {
            auto data = pq.top();
            int stops = data.first;
            int distance = data.second.first;
            int node = data.second.second;
            pq.pop();
            if (stops > k) {
                continue;
            }
            for (auto& i : adj[node]) {
                if (dist[i.second] > i.first + distance) {
                    dist[i.second] = i.first + distance;
                    pq.push({stops + 1, {dist[i.second], i.second}});
                }
            }
        }
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};