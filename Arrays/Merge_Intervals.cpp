#include <bits/stdc++.h>  
using namespace std;

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            vector<vector<int>> ans;
            sort(intervals.begin(), intervals.end());
            vector<int> idx = intervals[0];
            for (int i = 1; i < intervals.size(); i++) {
                if (max(idx[0], intervals[i][0]) <= min(idx[1], intervals[i][1])) {
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