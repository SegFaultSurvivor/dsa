#include <bits/stdc++.h>
int fun(int idx, int prev, vector<vector<int>>& points,
        vector<vector<int>>& dp) {
    if (idx == points.size()) {
        return 0;
    }
    if (dp[idx][prev + 1] != -1) {
        return dp[idx][prev + 1];
    }
    int maxi = INT_MIN;
    for (int i = 0; i < 3; i++) {
        if (i != prev) {
            int ans = points[idx][i] + fun(idx + 1, i, points, dp);
            maxi = max(ans, maxi);
        }
    }
    return dp[idx][prev + 1] = maxi;
}
int ninjaTraining(int n, vector<vector<int>>& points) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    int ans = fun(0, -1, points, dp);
    return ans;
}