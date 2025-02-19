#include <bits/stdc++.h>  
using namespace std;

class Solution {
    public:
        string reverseWords(string s) {
            int l, r;
            string ans = "";
            string temp;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != ' ') {
                    l = i;
                    break;
                }
            }
            for (int j = s.size() - 1; j >= 0; j--) {
                if (s[j] != ' ') {
                    r = j;
                    break;
                }
            }
            for (int k = r; k >= l; k--) {
                if (s[k] != ' ') {
                    temp += s[k];
                } else {
                    if (temp.size() != 0) {
                        reverse(temp.begin(), temp.end());
                        ans += temp;
                        ans += ' ';
                        temp = "";
                    }
                }
            }
            reverse(temp.begin(), temp.end());
            ans += temp;
            return ans;
        }
    };