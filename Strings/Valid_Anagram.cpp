#include <bits/stdc++.h>  
using namespace std;

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if (s.size() != t.size())
                return 0;
            unordered_map<char, int> m1, m2;
            for (int i = 0; i < s.size(); i++) {
                m1[s[i]]++;
                m2[t[i]]++;
            }
            return (m1 == m2) ? 1 : 0;
        }
    };