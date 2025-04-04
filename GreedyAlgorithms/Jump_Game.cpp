class Solution {
    public:
        bool fun(vector<int>& nums, int idx, vector<int>& dp) {
            if (idx == nums.size() - 1) {
                return 1;
            }
            if (dp[idx] != -1) {
                return dp[idx];
            }
            int jumps = nums[idx];
            if (jumps == 0) {
                return 0;
            }
            for (int i = 0; i < jumps; i++) {
                bool flag = fun(nums, idx + i + 1, dp);
                dp[idx] = flag;
                if (flag == 1) {
                    return 1;
                }
            }
            return 0;
        }
        bool canJump(vector<int>& nums) {
            if (nums[0] == 0 && nums.size() != 1) {
                return 0;
            }
            vector<int> dp(nums.size(), -1);
            bool ans = fun(nums, 0, dp);
            return ans;
        }
    };
    