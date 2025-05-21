class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        dist[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            auto data = pq.top();
            pq.pop();
            int distance = data.first;
            int row = data.second.first;
            int col = data.second.second;
            if (row == m - 1 && col == n - 1) {
                return distance;
            }
            for (auto& d : dir) {
                int temp_row = row + d.first;
                int temp_col = col + d.second;
                if (temp_row >= 0 && temp_row < m && temp_col >= 0 &&
                    temp_col < n) {
                    int current_diff =
                        abs(heights[row][col] - heights[temp_row][temp_col]);
                    int max_effort = max(distance, current_diff);
                    if (max_effort < dist[temp_row][temp_col]) {
                        dist[temp_row][temp_col] = max_effort;
                        pq.push({max_effort, {temp_row, temp_col}});
                    }
                }
            }
        }
        return -1;
    }
};