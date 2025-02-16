#include <bits/stdc++.h>  
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int i = 0;
            int j = 1, k = 1;
            if (nums.size() == 1) {
                return 1;
            }
            while (i != nums.size() - 1) {
                if (nums[i] != nums[j]) {
                    nums[k] = nums[j];
                    k++;
                }
                i++;
                j++;
            }
            return k;
        }
    };