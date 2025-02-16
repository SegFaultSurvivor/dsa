#include <bits/stdc++.h>  
using namespace std; 

class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) {
                return 0;
            }
            string st = to_string(x);
            for (int i = 0, j = st.size() - 1; i < j; i++, j--) {
                if (st[i] != st[j]) {
                    return 0;
                }
            }
            return 1;
        }
    };