class Solution {
    public:
        int fun(vector<int>& arr, int k, int start, vector<int>& dp) {
            if (start == arr.size()) {
                return 0;
            }
            if (dp[start] != -1) {
                return dp[start];
            }
            int maxi1 = INT_MIN, maxi2 = INT_MIN;
            for (int i = start; i < min((int)arr.size(), start + k); i++) {
                maxi1 = max(maxi1, arr[i]);
                int res = (i + 1 - start) * maxi1 + fun(arr, k, i + 1, dp);
                maxi2 = max(maxi2, res);
            }
            return dp[start] = maxi2;
        }
        int maxSumAfterPartitioning(vector<int>& arr, int k) {
            vector<int> dp(arr.size(), -1);
            int ans = fun(arr, k, 0, dp);
            return ans;
        }
    };