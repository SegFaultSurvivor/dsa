#include <bits/stdc++.h>  
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<pair<int, int>> ans;
            for (int i = 0; i < nums.size(); i++) {
                ans.push_back({i, nums[i]});
            }
            sort(ans.begin(), ans.end(),
                 [](auto a, auto b) { return a.second < b.second; });
            int i = 0, j = ans.size() - 1;
            while (i < j) {
                if (ans[i].second + ans[j].second == target) {
                    return {ans[i].first, ans[j].first};
                } else if (ans[i].second + ans[j].second > target) {
                    j--;
                } else {
                    i++;
                }
            }
            return {-1, -1};
        }
    };