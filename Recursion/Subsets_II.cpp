class Solution {
    public:
        vector<vector<int>> ans;
        void fun(vector<int>& candidates, int idx, vector<int>& temp) {
            if (idx == candidates.size()) {
                return;
            }
            for (int i = idx; i < candidates.size(); i++) {
                if (i > idx && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                temp.push_back(candidates[i]);
                ans.push_back(temp);
                fun(candidates, i + 1, temp);
                temp.pop_back();
            }
        }
        vector<vector<int>> subsetsWithDup(vector<int>& candidates) {
            sort(candidates.begin(), candidates.end());
            vector<int> temp;
            fun(candidates, 0, temp);
            ans.push_back({});
            return ans;
        }
    };
    