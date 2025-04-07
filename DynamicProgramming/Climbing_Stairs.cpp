class Solution {
    public:
        int fun(int n, vector<int>& dp) {
            if (n == 0) {
                return 1;
            }
            if (n < 0) {
                return 0;
            }
            if (dp[n] != 0) {
                return dp[n];
            }
            int one_step = fun(n - 1, dp);
            int two_step = fun(n - 2, dp);
            return dp[n] = one_step + two_step;
        }
        int climbStairs(int n) {
            vector<int> dp(n + 1, 0);
            int ans = fun(n, dp);
            return ans;
        }
    };