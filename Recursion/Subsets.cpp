class Solution {
    public:
        vector<vector<int>> ans;
        void fun(vector<int>& nums, vector<int> temp, int idx) {
            if (idx == nums.size()) {
                return;
            }
            for (int i = idx; i < nums.size(); i++) {
                temp.push_back(nums[i]);
                ans.push_back(temp);
                fun(nums, temp, i + 1);
                temp.pop_back();
            }
        }
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<int> temp;
            fun(nums, temp, 0);
            ans.push_back({});
            return ans;
        }
    };