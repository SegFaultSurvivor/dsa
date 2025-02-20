#include <bits/stdc++.h>  
using namespace std;


class Solution {
    public:
        int numberOfSubstrings(string s) {
            int a = -1, b = -1, c = -1;
            int l = 0, r = 0;
            int count = 0;
            while (r < s.size()) {
                if (s[r] == 'a') {
                    a = r;
                } else if (s[r] == 'b') {
                    b = r;
                } else if (s[r] == 'c') {
                    c = r;
                }
                if (a != -1 && b != -1 && c != -1) {
                    int l = min({a, b, c});
                    count = count + 1 + l;
                }
                r++;
            }
            return count;
        }
    };