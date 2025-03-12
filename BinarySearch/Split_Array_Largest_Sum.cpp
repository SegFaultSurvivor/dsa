class Solution {
    public:
        bool fun(vector<int>& nums, int k, int mid) {
            int students = 1, sum = 0;
            for (auto& i : nums) {
                sum += i;
                if (sum > mid) {
                    students++;
                    sum = i;
                }
            }
            if (students <= k) {
                return 1;
            }
            return 0;
        }
        int splitArray(vector<int>& nums, int k) {
            int l = *max_element(nums.begin(), nums.end());
            int r = accumulate(nums.begin(), nums.end(), 0);
            while (l <= r) {
                int mid = (l + r) / 2;
                bool students = fun(nums, k, mid);
                if (students) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        }
    };