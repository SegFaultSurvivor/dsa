#include <bits/stdc++.h>  
using namespace std;

#define ll long long
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int l, r;
        ll sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            l = i + 1, r = nums.size() - 1;
            while (l < r) {
                sum = (ll)nums[i] + (ll)nums[l] + (ll)nums[r];
                if (sum == 0) {
                    st.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        for (auto& i : st) {
            ans.push_back(i);
        }
        return ans;
    }
};