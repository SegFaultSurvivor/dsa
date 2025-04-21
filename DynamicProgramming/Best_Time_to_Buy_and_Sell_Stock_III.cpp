class Solution {
    public:
        int fun(vector<int>& prices, vector<vector<vector<int>>>& dp, int idx,
                int flag, int transactions) {
            if (idx == prices.size() || transactions == 0) {
                return 0;
            }
            if (dp[idx][flag][transactions] != -1) {
                return dp[idx][flag][transactions];
            }
            if (flag == 0) {
                int buy =
                    fun(prices, dp, idx + 1, !flag, transactions) - prices[idx];
                int not_buy = fun(prices, dp, idx + 1, flag, transactions);
                return dp[idx][flag][transactions] = max(buy, not_buy);
            } else {
                int sell =
                    fun(prices, dp, idx + 1, !flag, transactions - 1) + prices[idx];
                int not_sell = fun(prices, dp, idx + 1, flag, transactions);
                return dp[idx][flag][transactions] = max(sell, not_sell);
            }
        }
        int maxProfit(vector<int>& prices) {
            vector<vector<vector<int>>> dp(
                prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
            int ans = fun(prices, dp, 0, 0, 2);
            return (ans < 0) ? 0 : ans;
        }
    };