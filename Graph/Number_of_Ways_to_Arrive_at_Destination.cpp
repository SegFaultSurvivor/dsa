#define mod 1000000007
#define ll long long
class Solution {
public:
    int countPaths(int V, vector<vector<int>>& roads) {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                       greater<pair<ll, int>>>
            pq;
        vector<vector<pair<int, int>>> adj(V);
        vector<ll> dist(V, LLONG_MAX);
        vector<int> ways(V, 0);
        for (auto& i : roads) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adj[u].push_back({wt, v});
            adj[v].push_back({wt, u});
        }
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto data = pq.top();
            ll distance = data.first;
            int node = data.second;
            int current_ways = ways[node];
            pq.pop();
            for (auto& i : adj[node]) {
                ll newCost = i.first + distance;
                if (dist[i.second] > newCost) {
                    ways[i.second] = current_ways;
                    dist[i.second] = newCost;
                    pq.push({dist[i.second], i.second});
                } else if (dist[i.second] == newCost) {
                    ways[i.second] = (current_ways + ways[i.second]) % mod;
                }
            }
        }
        return ways[V - 1];
    }
};