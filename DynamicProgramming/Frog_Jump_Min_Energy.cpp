#include <bits/stdc++.h> 
int fun(int idx, vector<int>& heights, vector<int>& dp) {
    if (idx == heights.size() - 1) {
        return 0;
    }
    if (idx >= heights.size()) {
        return INT_MAX / 2;
    }
    if (dp[idx] != -1) {
        return dp[idx];
    }
    int one_step =
        abs(heights[idx + 1] - heights[idx]) + fun(idx + 1, heights, dp);
    int two_step =
        abs(heights[idx + 2] - heights[idx]) + fun(idx + 2, heights, dp);
    return dp[idx] = min(one_step, two_step);
}
int frogJump(int n, vector<int>& heights) {
    vector<int> dp(n + 1, -1);
    int ans = fun(0, heights, dp);
    return ans;
}