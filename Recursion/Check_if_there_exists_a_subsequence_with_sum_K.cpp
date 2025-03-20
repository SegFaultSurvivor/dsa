class Solution {
    public:
        bool flag = 0;
        void fun(vector<int> nums, int idx, int sum, int k) {
            if (sum == k) {
                flag = 1;
                return;
            }
            if (idx == nums.size() || flag == 1 || sum > k) {
                return;
            }
            for (int i = idx; i < nums.size(); i++) {
                if (flag == 0) {
                    sum += nums[i];
                    fun(nums, i + 1, sum, k);
                    sum -= nums[i];
                }
            }
        }
        bool checkSubsequenceSum(int n, vector<int>& nums, int k) {
            flag = 0;
            fun(nums, 0, 0, k);
            return flag;
        }
    };