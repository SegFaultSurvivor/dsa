#include <bits/stdc++.h>  
using namespace std;

class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int maxi = INT_MIN, count = 0;
            for (auto& i : nums) {
                if (i != 1) {
                    maxi = max(maxi, count);
                    count = 0;
                } else {
                    count++;
                }
            }
            maxi = max(maxi, count);
            return maxi;
        }
    };