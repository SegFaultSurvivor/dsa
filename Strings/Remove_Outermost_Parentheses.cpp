#include <bits/stdc++.h>  
using namespace std;

class Solution {
    public:
        string removeOuterParentheses(string s) {
            string ans = "";
            int count = 0;
            for (auto& i : s) {
                if (i == '(') {
                    count++;
                    if (count > 1) {
                        ans += i;
                    }
                } else {
                    count--;
                    if (count >= 1) {
                        ans += i;
                    }
                }
            }
            return ans;
        }
    };