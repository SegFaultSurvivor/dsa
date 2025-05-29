class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<pair<int, int>, pair<int, int>>,
                       vector<pair<pair<int, int>, pair<int, int>>>,
                       greater<pair<pair<int, int>, pair<int, int>>>>
            pq;
        vector<int> vis(points.size(), -1);
        pq.push({{0, 0}, {points[0][0], points[0][1]}});
        int sum = 0;
        while (!pq.empty()) {
            auto data = pq.top();
            pq.pop();
            int distance = data.first.first;
            int node = data.first.second;
            int x1 = data.second.first;
            int y1 = data.second.second;
            if (vis[node] == 1) {
                continue;
            }
            vis[node] = 1;
            sum += distance;
            for (int i = 0; i < points.size(); i++) {
                if (vis[i] == -1) {
                    int x2 = points[i][0];
                    int y2 = points[i][1];
                    int manhattan = abs(x1 - x2) + abs(y1 - y2);
                    pq.push({{manhattan, i}, {x2, y2}});
                }
            }
        }
        return sum;
    }
};