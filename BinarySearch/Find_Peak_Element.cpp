class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int l = 0, r = nums.size() - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (mid == 0 || mid == nums.size() - 1) {
                    if (mid == 0 && nums[mid] > nums[mid + 1]) {
                        return mid;
                    } else if (mid == 0 && nums[mid] < nums[mid + 1]) {
                        return mid + 1;
                    } else if (mid == nums.size() - 1 &&
                               nums[mid] > nums[mid - 1]) {
                        return mid;
                    } else {
                        return mid - 1;
                    }
                }
                if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                    return mid;
                } else if (nums[mid - 1] > nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        }
    };