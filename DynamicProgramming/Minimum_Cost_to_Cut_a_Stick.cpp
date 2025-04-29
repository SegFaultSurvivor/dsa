class Solution {
    public:
        int fun(vector<int>& cuts, int start, int end, int cur_start, int cur_end,
                vector<vector<int>>& dp) {
            if (cur_start > cur_end) {
                return 0;
            }
            if (dp[cur_start][cur_end] != -1) {
                return dp[cur_start][cur_end];
            }
            int mini = INT_MAX;
            for (int i = cur_start; i <= cur_end; i++) {
                int res = fun(cuts, start, cuts[i], cur_start, i - 1, dp) +
                          fun(cuts, cuts[i], end, i + 1, cur_end, dp) +
                          (end - start);
                mini = min(mini, res);
            }
            return dp[cur_start][cur_end] = mini;
        }
        int minCost(int n, vector<int>& cuts) {
            vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));
            sort(cuts.begin(), cuts.end());
            int ans = fun(cuts, 0, n, 0, cuts.size() - 1, dp);
            return ans;
        }
    };