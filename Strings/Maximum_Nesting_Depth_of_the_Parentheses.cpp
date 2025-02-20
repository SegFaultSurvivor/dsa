#include <bits/stdc++.h>  
using namespace std;

class Solution {
    public:
        int maxDepth(string s) {
            int maxi = INT_MIN;
            int count = 0;
            for (auto& i : s) {
                if (i == '(') {
                    count++;
                } else if (i == ')') {
                    count--;
                }
                maxi = max(maxi, count);
            }
            return maxi;
        }
    };