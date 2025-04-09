class Solution {
    public:
        int fun(int i, int j, vector<vector<int>>& dp) {
            if (i == dp.size() - 1 && j == dp[0].size() - 1) {
                return 1;
            }
            if (i >= dp.size() || j >= dp[0].size()) {
                return 0;
            }
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            int right = fun(i, j + 1, dp);
            int down = fun(i + 1, j, dp);
            return dp[i][j] = right + down;
        }
        int uniquePaths(int m, int n) {
            vector<vector<int>> dp(m, vector<int>(n, -1));
            int ans = fun(0, 0, dp);
            return ans;
        }
    };
    