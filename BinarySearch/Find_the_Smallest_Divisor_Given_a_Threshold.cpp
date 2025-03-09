class Solution {
    public:
        bool fun(vector<int>& nums, int mid, int threshold) {
            int sum = 0;
            for (auto& i : nums) {
                sum += ceil((double)i / mid);
            }
            if (sum <= threshold) {
                return 1;
            }
            return 0;
        }
        int smallestDivisor(vector<int>& nums, int threshold) {
            int l = 1;
            int r = *max_element(nums.begin(), nums.end());
            while (l <= r) {
                int mid = (l + r) / 2;
                bool sum = fun(nums, mid, threshold);
                if (sum) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        }
    };