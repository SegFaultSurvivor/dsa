#include <bits/stdc++.h>  
using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string ans = "";
            sort(strs.begin(), strs.end());
            for (int i = 0; i < max(strs[0].size(), strs[strs.size() - 1].size());
                 i++) {
                if (strs[0][i] != strs[strs.size() - 1][i]) {
                    break;
                } else {
                    ans += strs[0][i];
                }
            }
            return ans;
        }
    };