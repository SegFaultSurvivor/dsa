class Solution {
    public:
        vector<vector<pair<int, int>>> dp;
        pair<int, int> fun(vector<int>& nums, int idx, int prev_idx) {
            if (idx == nums.size()) {
                return {0, 1};
            }
            if (dp[idx][prev_idx + 1].first != -1) {
                return dp[idx][prev_idx + 1];
            }
            pair<int, int> take = {0, 0};
            if (prev_idx == -1 || nums[idx] > nums[prev_idx]) {
                take = fun(nums, idx + 1, idx);
                take.first += 1;
            }
            pair<int, int> nottake = fun(nums, idx + 1, prev_idx);
            if (take.first == nottake.first) {
                dp[idx][prev_idx + 1] = {take.first, take.second + nottake.second};
            } else if (take.first > nottake.first) {
                dp[idx][prev_idx + 1] = take;
            } else {
                dp[idx][prev_idx + 1] = nottake;
            }
    
            return dp[idx][prev_idx + 1];
        }
    
        int findNumberOfLIS(vector<int>& nums) {
            dp.assign(nums.size(),
                      vector<pair<int, int>>(nums.size() + 1, {-1, -1}));
            return fun(nums, 0, -1).second;
        }
    };
    