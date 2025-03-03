class Solution {
    public:
        int fun(vector<int>& nums, int k) {
            if (k < 0) {
                return 0;
            }
            int l = 0, r = 0;
            int count = 0;
            while (r < nums.size()) {
                if (nums[r] % 2 != 0) {
                    k--;
                }
                while (k < 0) {
                    if (nums[l] % 2 != 0) {
                        k++;
                    }
                    l++;
                }
                count += r - l + 1;
                r++;
            }
            return count;
        }
        int numberOfSubarrays(vector<int>& nums, int k) {
            int ans = fun(nums, k) - fun(nums, k - 1);
            return ans;
        }
    };