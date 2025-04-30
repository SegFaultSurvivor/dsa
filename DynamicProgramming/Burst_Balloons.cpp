class Solution {
    public:
        int fun(vector<int>& nums, vector<vector<int>>& dp, int start, int end) {
            if (start > end) {
                return 0;
            }
            if (dp[start][end] != -1) {
                return dp[start][end];
            }
            int maxi = INT_MIN;
            for (int i = start; i <= end; i++) {
                int left = (start - 1 < 0) ? 1 : nums[start - 1];
                int right = (end + 1 >= nums.size()) ? 1 : nums[end + 1];
                int res = fun(nums, dp, start, i - 1) + fun(nums, dp, i + 1, end) +
                          left * nums[i] * right;
                maxi = max(res, maxi);
            }
            return dp[start][end] = maxi;
        }
        int maxCoins(vector<int>& nums) {
            vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
            int ans = fun(nums, dp, 0, nums.size() - 1);
            return ans;
        }
    };