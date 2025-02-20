#include <bits/stdc++.h>  
using namespace std;

#define mod 1000000007
class Solution {
public:
    int countHomogenous(string s) {
        int l = 0, r = 0;
        int count = 0;
        unordered_set<char> st;
        while (r < s.size()) {
            st.insert(s[r]);
            if (st.size() > 1) {
                st.erase(s[l]);
                l = r;
            }
            count = (count + (r - l + 1)) % mod;
            r++;
        }
        return count;
    }
};