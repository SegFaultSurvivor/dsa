#include <bits/stdc++.h>  
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int sum = 0, maxi = INT_MIN;
            for (auto& i : nums) {
                sum += i;
                maxi = max(maxi, sum);
                if (sum < 0) {
                    sum = 0;
                }
            }
            return maxi;
        }
    };