#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int fun(int n, int k, vector<int>& arr, vector<vector<int>>& dp, int idx,
        int sum) {
    if (sum == k)
        return 1;
    if (sum > k || idx == n)
        return 0;
    if (dp[idx][sum] != -1)
        return dp[idx][sum];

    int ans = 0;
    int prev_sum = sum;

    for (int i = idx; i < n; i++) {
        sum += arr[i];
        if (sum > k) {
            sum -= arr[i];
            continue;
        }
        ans = (ans + fun(n, k, arr, dp, i + 1, sum)) % MOD;
        sum -= arr[i];
    }

    return dp[idx][prev_sum] = ans;
}

int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return fun(n, k, arr, dp, 0, 0);
}
