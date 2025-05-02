class Solution {
    public:
        int fun(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j,
                int row, int col) {
            if (i == row || j == col) {
                return 0;
            }
            if (matrix[i][j] == 0) {
                return 0;
            }
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            int right = 1 + fun(matrix, dp, i, j + 1, row, col);
            int diagonal = 1 + fun(matrix, dp, i + 1, j + 1, row, col);
            int down = 1 + fun(matrix, dp, i + 1, j, row, col);
    
            return dp[i][j] = min({right, diagonal, down});
        }
        int countSquares(vector<vector<int>>& matrix) {
            int row = matrix.size(), col = matrix[0].size();
            vector<vector<int>> dp(row, vector<int>(col, -1));
            int ans = 0;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    ans += fun(matrix, dp, i, j, row, col);
                }
            }
            return ans;
        }
    };