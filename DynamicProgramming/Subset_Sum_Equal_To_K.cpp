#include <bits/stdc++.h>
bool fun(int n, int k, vector<int>& arr, vector<vector<int>>& dp, int idx,
         int sum) {
    if (sum == k) {
        return 1;
    }
    if (sum > k || idx == n) {
        return 0;
    }
    if (dp[idx][sum] != -1) {
        return dp[idx][sum];
    }
    for (int i = idx; i < n; i++) {
        sum += arr[i];
        if (sum > k) {
            sum -= arr[i];
            continue;
        }
        bool flag = fun(n, k, arr, dp, i + 1, sum);
        dp[idx][sum] = flag;
        if (flag == 1) {
            return 1;
        }
        sum -= arr[i];
    }
    return 0;
}
bool subsetSumToK(int n, int k, vector<int>& arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    bool ans = fun(n, k, arr, dp, 0, 0);
    return ans;
}