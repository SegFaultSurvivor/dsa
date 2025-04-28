class Solution {
    public:
     int fun(vector<int>& nums, vector<vector<int>>& dp, int start, int end) {
         if (start == end) {
             return 0;
         }
         if (dp[start][end] != -1) {
             return dp[start][end];
         }
         int ans = INT_MAX;
         for (int i = start; i < end; i++) {
             int mini = fun(nums, dp, start, i) + fun(nums, dp, i + 1, end) +
                        (nums[start] * nums[i + 1] * nums[end + 1]);
             ans = min(mini, ans);
         }
         return dp[start][end] = ans;
     }
     int matrixMultiplication(vector<int>& nums) {
         vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
         int ans = fun(nums, dp, 0, nums.size() - 2);
         return ans;
     }
 };