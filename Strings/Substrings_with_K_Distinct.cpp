#include <bits/stdc++.h>  
using namespace std;


class Solution {
    public:
        int fun(string& s, int k) {
            if (k == 0)
                return 0;
            int l = 0, r = 0, count = 0;
            unordered_map<char, int> freq;
    
            while (r < s.size()) {
                freq[s[r]]++;
    
                while (freq.size() > k) {
                    freq[s[l]]--;
                    if (freq[s[l]] == 0) {
                        freq.erase(s[l]);
                    }
                    l++;
                }
    
                count += (r - l + 1);
                r++;
            }
            return count;
        }
    
        int countSubstr(string& s, int k) { return fun(s, k) - fun(s, k - 1); }
    };