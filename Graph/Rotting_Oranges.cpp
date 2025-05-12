class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            queue<pair<int, int>> q;
            vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), -1));
            vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
            int time = 0;
            int fresh_oranges = 0;
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    if (grid[i][j] == 2) {
                        q.push({i, j});
                        vis[i][j] = 2;
                    }
                    if (grid[i][j] == 1) {
                        fresh_oranges++;
                    }
                }
            }
            if (fresh_oranges == 0) {
                return 0;
            }
            while (!q.empty()) {
                int len = q.size();
                time++;
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
                            vis[temp_row][temp_col] == -1 &&
                            grid[temp_row][temp_col] == 1) {
                            q.push({temp_row, temp_col});
                            vis[temp_row][temp_col] = 2;
                            fresh_oranges--;
                        }
                    }
                }
            }
            return (fresh_oranges == 0) ? time - 1 : -1;
        }
    };