class Solution {
    public:
        int fun(vector<int>& nums, int target, vector<vector<int>>& dp, int idx,
                int sum, int offset) {
            if (idx == nums.size()) {
                return sum == target ? 1 : 0;
            }
            if (dp[idx][sum + offset] != -1) {
                return dp[idx][sum + offset];
            }
            int negative = fun(nums, target, dp, idx + 1, sum - nums[idx], offset);
            int positive = fun(nums, target, dp, idx + 1, sum + nums[idx], offset);
            return dp[idx][sum + offset] = negative + positive;
        }
    
        int findTargetSumWays(vector<int>& nums, int target) {
            int totalSum = accumulate(nums.begin(), nums.end(), 0);
            if (target > totalSum || target < -totalSum)
                return 0;
    
            vector<vector<int>> dp(nums.size(), vector<int>(2 * totalSum + 1, -1));
            return fun(nums, target, dp, 0, 0, totalSum);
        }
    };
    