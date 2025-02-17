#include <bits/stdc++.h>  
using namespace std;

class Solution {
    public:
        int longestSubarray(vector<int>& arr, int k) {
            unordered_map<int, int> mp;
            int n = arr.size();
            int sum = 0;
            int maxi = 0;
            for (int i = 0; i < n; i++) {
                sum += arr[i];
                if (sum == k) {
                    maxi = max(maxi, i + 1);
                }
                if (mp.find(sum - k) != mp.end()) {
                    maxi = max(maxi, i - mp[sum - k]);
                }
                if (mp.find(sum) == mp.end()) {
                    mp[sum] = i;
                }
            }
            return maxi;
        }
    };