#include <bits/stdc++.h>  
using namespace std;

class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            if (s.size() != t.size())
                return 0;
            unordered_map<char, char> m1, m2;
            for (int i = 0; i < s.size(); i++) {
                char c1 = s[i], c2 = t[i];
                if (m1.count(c1) && m1[c1] != c2)
                    return 0;
                if (m2.count(c2) && m2[c2] != c1)
                    return 0;
                m1[c1] = c2;
                m2[c2] = c1;
            }
            return 1;
        }
    };