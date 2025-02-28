class Solution {
    public:
        int fun(vector<int>& nums, int goal) {
            if (goal < 0) {
                return 0;
            }
            int l = 0, r = 0;
            int ans = 0, count = 0;
            while (r < nums.size()) {
                ans += nums[r];
                while (ans > goal) {
                    ans -= nums[l];
                    l++;
                }
                count += r - l + 1;
                r++;
            }
            return count;
        }
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            int ans = fun(nums, goal) - fun(nums, goal - 1);
            return ans;
        }
    };