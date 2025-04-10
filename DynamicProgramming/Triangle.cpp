class Solution {
    public:
        int fun(int i, int j, vector<vector<int>>& triangle,
                vector<vector<int>>& dp) {
            if (i == triangle.size()) {
                return 0;
            }
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            int down = triangle[i][j] + fun(i + 1, j, triangle, dp);
            int right_down = triangle[i][j] + fun(i + 1, j + 1, triangle, dp);
            return dp[i][j] = min(down, right_down);
        }
        int minimumTotal(vector<vector<int>>& triangle) {
            vector<vector<int>> dp(triangle.size(),
                                   vector<int>(triangle.size(), -1));
            int ans = fun(0, 0, triangle, dp);
            return ans;
        }
    };