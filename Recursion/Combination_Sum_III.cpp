class Solution {
    public:
        vector<vector<int>> ans;
        void fun(int value, int target, vector<int>& temp, int k) {
            if (target == 0 && k == 0) {
                ans.push_back(temp);
                return;
            }
            if (k < 0 || target < 0 || value > 9) {
                return;
            }
            temp.push_back(value);
            fun(value + 1, target - value, temp, k - 1);
            temp.pop_back();
            fun(value + 1, target, temp, k);
        }
        vector<vector<int>> combinationSum3(int k, int target) {
            vector<int> temp;
            fun(1, target, temp, k);
            return ans;
        }
    };