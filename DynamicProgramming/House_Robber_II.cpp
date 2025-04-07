class Solution {
    public:
        int fun(int idx, int end, vector<int>& nums, vector<int>& dp) {
            if (idx > end) {
                return 0;
            }
            if (dp[idx] != -1) {
                return dp[idx];
            }
    
            int maxi = INT_MIN;
            for (int i = idx; i <= end; i++) {
                int res = nums[i] + fun(i + 2, end, nums, dp);
                maxi = max(maxi, res);
            }
    
            return dp[idx] = maxi;
        }
    
        int rob(vector<int>& nums) {
            int n = nums.size();
            if (n == 1)
                return nums[0];
    
            vector<int> dp1(n, -1);
            int ans1 = fun(0, n - 2, nums, dp1);
    
            vector<int> dp2(n, -1);
            int ans2 = fun(1, n - 1, nums, dp2);
    
            return max(ans1, ans2);
        }
    };
    