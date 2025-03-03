class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int l = 0, r = 0;
            int maxi = 0;
            while (r < nums.size()) {
                if (nums[r] == 0) {
                    k--;
                }
                while (k < 0) {
                    if (nums[l] == 0) {
                        k++;
                    }
                    l++;
                }
                maxi = max(maxi, r - l + 1);
                r++;
            }
            return maxi;
        }
    };