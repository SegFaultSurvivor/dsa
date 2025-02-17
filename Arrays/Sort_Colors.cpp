#include <bits/stdc++.h>  
using namespace std;

class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int zero = 0, one = 0, two = 0;
            for (auto& i : nums) {
                if (i == 0)
                    zero++;
                else if (i == 1)
                    one++;
                else
                    two++;
            }
            for (int i = 0; i < zero; i++) {
                nums[i] = 0;
            }
            for (int i = zero; i < zero + one; i++) {
                nums[i] = 1;
            }
            for (int i = zero + one; i < nums.size(); i++) {
                nums[i] = 2;
            }
        }
    };