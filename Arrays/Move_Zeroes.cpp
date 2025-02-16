#include <bits/stdc++.h>  
using namespace std;

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int count = 0;
            vector<int> ans;
            for (auto& i : nums) {
                if (i == 0) {
                    count++;
                } else {
                    ans.push_back(i);
                }
            }
            while (count != 0) {
                ans.push_back(0);
                count--;
            }
            nums = ans;
        }
    };