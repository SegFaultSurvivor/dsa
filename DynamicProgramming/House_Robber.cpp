class Solution {
    public:
        int fun(int idx, vector<int>& nums, vector<int>& dp) {
            if (idx >= nums.size()) {
                return 0;
            }
            if (dp[idx] != -1) {
                return dp[idx];
            }
            int maxi = INT_MIN;
            for (int i = idx; i < nums.size(); i++) {
                int res = nums[i] + fun(i + 2, nums, dp);
                maxi = max(maxi, res);
            }
            return dp[idx] = maxi;
        }
        int rob(vector<int>& nums) {
            vector<int> dp(nums.size() + 1, -1);
            int ans = fun(0, nums, dp);
            return ans;
        }
    };