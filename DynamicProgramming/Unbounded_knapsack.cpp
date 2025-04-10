class Solution {
    public:
     int fun(int W, vector<int>& val, vector<int>& wt, int idx,
             vector<vector<int>>& dp) {
         if (W < 0) {
             return INT_MIN / 2;
         }
         if (idx == val.size()) {
             return 0;
         }
         if (dp[idx][W] != -1) {
             return dp[idx][W];
         }
 
         int take = val[idx] + fun(W - wt[idx], val, wt, idx, dp);
         int not_take = fun(W, val, wt, idx + 1, dp);
         return dp[idx][W] = max(take, not_take);
     }
     int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
         vector<vector<int>> dp(val.size() + 1, vector<int>(W + 1, -1));
         int maxi = fun(W, val, wt, 0, dp);
         return maxi;
     }
 };
 