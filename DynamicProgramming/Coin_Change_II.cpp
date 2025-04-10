class Solution {
    public:
        int fun(int sum, vector<int>& coins, int idx, vector<vector<int>>& dp) {
            if (sum < 0 || idx == coins.size()) {
                return 0;
            }
            if (sum == 0) {
                return 1;
            }
            if (dp[idx][sum] != -1) {
                return dp[idx][sum];
            }
    
            int take = fun(sum - coins[idx], coins, idx, dp);
            int not_take = fun(sum, coins, idx + 1, dp);
            return dp[idx][sum] = take + not_take;
        }
        int change(int sum, vector<int>& coins) {
            vector<vector<int>> dp(coins.size() + 1, vector<int>(sum + 1, -1));
            int mini = fun(sum, coins, 0, dp);
            return mini;
        }
    };