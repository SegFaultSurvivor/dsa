#include <bits/stdc++.h>  
using namespace std;

#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int l, r;
        ll sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    sum = (ll)nums[i] + (ll)nums[j] + (ll)nums[l] + (ll)nums[r];
                    if (sum == target) {
                        st.insert({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    } else if (sum < target) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        for (auto& i : st) {
            ans.push_back(i);
        }
        return ans;
    }
};