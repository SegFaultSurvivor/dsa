class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> ans(2, -1);
            int l = 0, r = nums.size() - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (nums[mid] < target) {
                    l = mid + 1;
                } else if (nums[mid] > target) {
                    r = mid - 1;
                } else if (nums[mid] == target) {
                    if (mid - 1 == -1 || nums[mid - 1] != target) {
                        ans[0] = mid;
                        break;
                    } else {
                        r = mid - 1;
                    }
                }
            }
            l = 0, r = nums.size() - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (nums[mid] < target) {
                    l = mid + 1;
                } else if (nums[mid] > target) {
                    r = mid - 1;
                } else if (nums[mid] == target) {
                    if (mid + 1 == (int)nums.size() || nums[mid + 1] != target) {
                        ans[1] = mid;
                        break;
                    } else {
                        l = mid + 1;
                    }
                }
            }
            return ans;
        }
    };