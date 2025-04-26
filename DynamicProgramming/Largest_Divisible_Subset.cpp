class Solution {
    public:
        int dp[1001];
        void fun(vector<int>& nums, int idx, vector<int>& ans, vector<int>& temp,
                 int prev_val) {
            if (idx == nums.size()) {
                if (temp.size() > ans.size()) {
                    ans = temp;
                }
                return;
            }
            if ((int)temp.size() > dp[idx] && (nums[idx] % prev_val == 0)) {
                dp[idx] = temp.size();
                temp.push_back(nums[idx]);
                fun(nums, idx + 1, ans, temp, nums[idx]);
                temp.pop_back();
            }
            fun(nums, idx + 1, ans, temp, prev_val);
        }
    
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            memset(dp, -1, sizeof(dp));
            sort(nums.begin(), nums.end());
            vector<int> ans;
            vector<int> temp;
            fun(nums, 0, ans, temp, 1);
            return ans;
        }
    };
    