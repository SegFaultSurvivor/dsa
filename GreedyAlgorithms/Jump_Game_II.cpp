class Solution {
    public:
        int fun(vector<int>& nums, int idx, vector<int>& dp) {
            if (idx == nums.size() - 1) {
                return 0;
            }
            if (idx >= nums.size()) {
                return INT_MAX / 2;
            }
            if (dp[idx] != -1) {
                return dp[idx];
            }
            int jumps = nums[idx];
            if (jumps == 0) {
                return INT_MAX / 2;
            }
            int mini = INT_MAX;
            for (int i = 0; i < jumps; i++) {
                int cur_jump = 1 + fun(nums, idx + i + 1, dp);
                mini = min(mini, cur_jump);
            }
            return dp[idx] = mini;
        }
        int jump(vector<int>& nums) {
            vector<int> dp(nums.size(), -1);
            int ans = fun(nums, 0, dp);
            return ans;
        }
    };