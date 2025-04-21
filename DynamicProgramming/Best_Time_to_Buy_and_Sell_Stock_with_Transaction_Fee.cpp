class Solution {
    public:
        int fun(vector<int>& prices, vector<vector<int>>& dp, int idx, int flag,
                int fee) {
            if (idx >= prices.size()) {
                return 0;
            }
            if (dp[idx][flag] != -1) {
                return dp[idx][flag];
            }
            if (flag == 0) {
                int buy = fun(prices, dp, idx + 1, !flag, fee) - prices[idx];
                int not_buy = fun(prices, dp, idx + 1, flag, fee);
                return dp[idx][flag] = max(buy, not_buy);
            } else {
                int sell = fun(prices, dp, idx + 1, !flag, fee) + prices[idx] - fee;
                int not_sell = fun(prices, dp, idx + 1, flag, fee);
                return dp[idx][flag] = max(sell, not_sell);
            }
        }
        int maxProfit(vector<int>& prices, int fee) {
            vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
            int ans = fun(prices, dp, 0, 0, fee);
            return (ans < 0) ? 0 : ans;
        }
    };