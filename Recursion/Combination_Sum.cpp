class Solution {
    public:
        vector<vector<int>> ans;
        void fun(vector<int>& candidates, int target, int idx, vector<int> temp) {
            if (target == 0) {
                ans.push_back(temp);
                return;
            }
            if (idx == candidates.size() || target < 0) {
                return;
            }
            temp.push_back(candidates[idx]);
            fun(candidates, target - candidates[idx], idx, temp);
            temp.pop_back();
            fun(candidates, target, idx + 1, temp);
        }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<int> temp;
            fun(candidates, target, 0, temp);
            return ans;
        }
    };