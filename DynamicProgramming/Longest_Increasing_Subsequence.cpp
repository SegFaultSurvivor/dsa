class Solution {
    public:
        int fun(vector<int>& nums, vector<vector<int>>& dp, int idx, int prev_idx) {
            if (idx == nums.size()) {
                return 0;
            }
            if (dp[idx][prev_idx + 1] != -1) {
                return dp[idx][prev_idx + 1];
            }
            int take = 0;
            if (prev_idx == -1 || nums[prev_idx] < nums[idx]) {
                take = 1 + fun(nums, dp, idx + 1, idx);
            }
            int not_take = fun(nums, dp, idx + 1, prev_idx);
            return dp[idx][prev_idx + 1] = max(take, not_take);
        }
        int lengthOfLIS(vector<int>& nums) {
            vector<vector<int>> dp(nums.size() + 1,
                                   vector<int>(nums.size() + 1, -1));
            int ans = fun(nums, dp, 0, -1);
            return ans;
        }
    };