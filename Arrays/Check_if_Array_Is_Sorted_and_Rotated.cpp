#include <bits/stdc++.h>  
using namespace std;

class Solution {
    public:
        bool check(vector<int>& nums) {
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (i == nums.size() - 1) {
                    if (nums[i] > nums[0] && count == 1) {
                        return 0;
                    }
                    return 1;
                }
                if (nums[i] > nums[i + 1]) {
                    if (count == 1) {
                        return 0;
                    }
                    count++;
                }
            }
            return 0;
        }
    };