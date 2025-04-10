class Solution {
    public:
        int fun(int i, int j, vector<vector<int>>& matrix,
                vector<vector<int>>& dp) {
            if (j < 0 || j >= matrix[0].size()) {
                return INT_MAX / 2;
            }
            if (i == matrix.size() - 1) {
                return matrix[i][j];
            }
            if (dp[i][j] != INT_MAX) {
                return dp[i][j];
            }
            int left = matrix[i][j] + fun(i + 1, j - 1, matrix, dp);
            int down = matrix[i][j] + fun(i + 1, j, matrix, dp);
            int right = matrix[i][j] + fun(i + 1, j + 1, matrix, dp);
            return dp[i][j] = min({left, down, right});
        }
    
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n = matrix.size(), m = matrix[0].size();
            vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
            int ans = INT_MAX;
            for (int j = 0; j < m; ++j) {
                ans = min(ans, fun(0, j, matrix, dp));
            }
            return ans;
        }
    };
    