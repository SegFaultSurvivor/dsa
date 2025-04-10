class Solution {
    public:
        int fun(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {
            if (i >= dp.size() || j >= dp[0].size()) {
                return INT_MAX / 2;
            }
            if (i == dp.size() - 1 && j == dp[0].size() - 1) {
                return grid[i][j];
            }
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            int right = grid[i][j] + fun(i, j + 1, dp, grid);
            int down = grid[i][j] + fun(i + 1, j, dp, grid);
            return dp[i][j] = min(right, down);
        }
        int minPathSum(vector<vector<int>>& grid) {
            vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
            int ans = fun(0, 0, dp, grid);
            return ans;
        }
    };