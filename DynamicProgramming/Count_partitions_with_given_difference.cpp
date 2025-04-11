#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int fun(int n, vector<int>& arr, vector<vector<int>>& dp, int target,
            int idx) {
        if (target == 0) {
            return 1;
        }
        if (idx == n || target < 0) {
            return 0;
        }
        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }
        int take = fun(n, arr, dp, target - arr[idx], idx + 1);
        int not_take = fun(n, arr, dp, target, idx + 1);
        return dp[idx][target] = take + not_take;
    }
    int countPartitions(int n, int diff, vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if ((sum + diff) % 2 != 0) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        int target = (sum + diff) / 2;
        int ans = fun(n, arr, dp, target, 0);
        return ans;
    }
};