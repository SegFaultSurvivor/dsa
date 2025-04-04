class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals,
                                   vector<int>& newInterval) {
            vector<vector<int>> ans;
            intervals.push_back(newInterval);
            sort(intervals.begin(), intervals.end());
            vector<int> idx = intervals[0];
            for (int i = 1; i < intervals.size(); i++) {
                if (intervals[i][0] <= min(idx[1], intervals[i][1])) {
                    idx[1] = max(idx[1], intervals[i][1]);
                } else {
                    ans.push_back(idx);
                    idx = intervals[i];
                }
            }
            ans.push_back(idx);
            return ans;
        }
    };