class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) {
            return -1;
        }
        vector<pair<int, int>> dir = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1},
                                      {1, 0},  {1, 1},   {0, 1},  {-1, 1}};
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto data = q.front();
                int row = data.second.first;
                int col = data.second.second;
                int distance = data.first;
                if (row == n - 1 && col == m - 1) {
                    return distance + 1;
                }
                q.pop();
                for (auto& i : dir) {
                    int temp_row = row + i.first;
                    int temp_col = col + i.second;
                    if (temp_row >= 0 && temp_row < n && temp_col >= 0 &&
                        temp_col < m && grid[temp_row][temp_col] == 0) {
                        grid[temp_row][temp_col] = 1;
                        q.push({distance + 1, {temp_row, temp_col}});
                    }
                }
            }
        }
        return -1;
    }
};