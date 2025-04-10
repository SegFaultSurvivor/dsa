class Solution {
    public:
        int fun(int sum, vector<int>& coins, int idx, vector<vector<int>>& dp) {
            if (sum < 0 || idx == coins.size()) {
                return INT_MAX / 2;
            }
            if (sum == 0) {
                return 0;
            }
            if (dp[idx][sum] != -1) {
                return dp[idx][sum];
            }
    
            int take = 1 + fun(sum - coins[idx], coins, idx, dp);
            int not_take = fun(sum, coins, idx + 1, dp);
            return dp[idx][sum] = min(take, not_take);
        }
        int coinChange(vector<int>& coins, int sum) {
            vector<vector<int>> dp(coins.size() + 1, vector<int>(sum + 1, -1));
            int mini = fun(sum, coins, 0, dp);
            return (mini == INT_MAX / 2) ? -1 : mini;
        }
    };