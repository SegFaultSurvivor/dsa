class Solution {
    public:
        bool fun(vector<int>& nums, vector<vector<int>>& dp, int idx, int target) {
            if (target == 0) {
                return 1;
            }
            if (idx == nums.size() || target < 0) {
                return 0;
            }
            if (dp[idx][target] != -1) {
                return dp[idx][target];
            }
            int take = fun(nums, dp, idx + 1, target - nums[idx]);
            int not_take = fun(nums, dp, idx + 1, target);
            return dp[idx][target] = take || not_take;
        }
        bool canPartition(vector<int>& nums) {
            int sum = accumulate(nums.begin(), nums.end(), 0);
            if (sum % 2 != 0) {
                return 0;
            }
            vector<vector<int>> dp(nums.size(), vector<int>(sum, -1));
            bool ans = fun(nums, dp, 0, sum / 2);
            return ans;
        }
    };