class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc,
                                  int color) {
        queue<pair<int, int>> q;
        vector<vector<int>> vis = grid;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        int original = grid[sr][sc];
        if (original == color)
            return grid;

        q.push({sr, sc});
        grid[sr][sc] = color;
        vis[sr][sc] = color;

        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                pair<int, int> node = q.front();
                int row = node.first;
                int col = node.second;
                q.pop();
                for (auto& i : dir) {
                    int temp_row = row + i.first;
                    int temp_col = col + i.second;
                    if (temp_row >= 0 && temp_row < grid.size() &&
                        temp_col >= 0 && temp_col < grid[0].size() &&
                        vis[temp_row][temp_col] == original) {
                        q.push({temp_row, temp_col});
                        grid[temp_row][temp_col] = color;
                        vis[temp_row][temp_col] = color;
                    }
                }
            }
        }
        return grid;
    }
};
