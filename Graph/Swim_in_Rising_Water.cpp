class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> dis(grid.size(),
                                vector<int>(grid[0].size(), INT_MAX));
        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        dis[0][0] = grid[0][0];
        pq.push({dis[0][0], {0, 0}});
        while (!pq.empty()) {
            auto data = pq.top();
            pq.pop();
            int distance = data.first;
            int row = data.second.first;
            int col = data.second.second;
            if (row == grid.size() - 1 && col == grid[0].size() - 1) {
                return distance;
            }
            for (auto& d : dir) {
                int temp_row = row + d.first;
                int temp_col = col + d.second;
                if (temp_row >= 0 && temp_row < grid.size() && temp_col >= 0 &&
                    temp_col < grid[0].size()) {
                    int maxi = max(distance, grid[temp_row][temp_col]);
                    if (maxi < dis[temp_row][temp_col]) {
                        dis[temp_row][temp_col] = maxi;
                        pq.push({maxi, {temp_row, temp_col}});
                    }
                }
            }
        }
        return -1;
    }
};