class Solution {
    public:
        int fun(int i, int j, vector<vector<int>>& dp,
                vector<vector<int>>& obstacleGrid) {
            if (i >= dp.size() || j >= dp[0].size()) {
                return 0;
            }
            if (obstacleGrid[i][j] == 1) {
                return 0;
            }
            if (i == dp.size() - 1 && j == dp[0].size() - 1) {
                return 1;
            }
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            int right = fun(i, j + 1, dp, obstacleGrid);
            int down = fun(i + 1, j, dp, obstacleGrid);
            return dp[i][j] = right + down;
        }
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            vector<vector<int>> dp(obstacleGrid.size(),
                                   vector<int>(obstacleGrid[0].size(), -1));
            int ans = fun(0, 0, dp, obstacleGrid);
            return ans;
        }
    };