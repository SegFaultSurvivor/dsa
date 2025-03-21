class Solution {
    public:
        bool flag = 0;
        void fun(vector<int>& candidates, int target, int idx, vector<int>& temp) {
            if (target == 0) {
                flag = 1;
                return;
            }
            if (idx == candidates.size() || target < 0) {
                return;
            }
            for (int i = idx; i < candidates.size(); i++) {
                if (flag == 0) {
                    if (i > idx && candidates[i] == candidates[i - 1]) {
                        continue;
                    }
                    temp.push_back(candidates[i]);
                    fun(candidates, target - candidates[i], i + 1, temp);
                    temp.pop_back();
                }
            }
        }
        bool isSubsetSum(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<int> temp;
            fun(candidates, target, 0, temp);
            return flag;
        }
    };