#include <bits/stdc++.h>  
using namespace std;

class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int maxi = INT_MIN;
            int product = 1;
            for (auto& i : nums) {
                product *= i;
                maxi = max(maxi, product);
                if (product == 0) {
                    product = 1;
                }
            }
            product = 1;
            for (int i = nums.size() - 1; i >= 0; i--) {
                product *= nums[i];
                maxi = max(maxi, product);
                if (product == 0) {
                    product = 1;
                }
            }
            return maxi;
        }
    };