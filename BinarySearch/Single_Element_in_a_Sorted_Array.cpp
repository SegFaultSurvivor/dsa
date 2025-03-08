class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            if (nums.size() == 1) {
                return nums[0];
            }
            int l = 0, r = nums.size() - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]) {
                    return nums[mid];
                } else if (nums[mid] == nums[mid - 1]) {
                    int left = mid - l + 1;
                    int right = r - mid;
                    if (left % 2 != 0) {
                        r = mid - 2;
                    } else {
                        l = mid + 1;
                    }
                } else {
                    int left = mid - l + 1;
                    int right = r - mid;
                    if (left % 2 == 0) {
                        r = mid - 1;
                    } else {
                        l = mid + 2;
                    }
                }
            }
            return nums[l];
        }
    };