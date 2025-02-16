#include <bits/stdc++.h>  
using namespace std; 

class Solution {
    public:
        bool isPalindrome(string s) {
            int i = 0, j = s.size() - 1;
            while (i < j) {
                if (isalnum(s[i]) && isalnum(s[j])) {
                    if (tolower(s[i]) != tolower(s[j])) {
                        return 0;
                    }
                    i++;
                    j--;
                } else if (!isalnum(s[i]) && !isalnum(s[j])) {
                    i++;
                    j--;
                } else if (!isalnum(s[i])) {
                    i++;
                } else {
                    j--;
                }
            }
            return 1;
        }
    };