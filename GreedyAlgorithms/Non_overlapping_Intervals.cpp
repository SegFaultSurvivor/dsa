class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end(),
                 [](auto& a, auto& b) { return a[1] < b[1]; });
            int ans = 0, freeTime = INT_MIN;
            for (auto& i : intervals) {
                if (i[0] >= freeTime) {
                    ans++;
                    freeTime = i[1];
                }
            }
            return intervals.size() - ans;
        }
    };