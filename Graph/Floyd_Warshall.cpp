class Solution {
public:
    void floydWarshall(vector<vector<int>>& dist) {
        int V = dist.size();
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < dist.size(); j++) {
                for (int k = 0; k < dist.size(); k++) {
                    if (dist[j][i] != 100000000 && dist[i][k] != 100000000) {
                        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
                    }
                }
            }
        }
    }
};