#include <bits/stdc++.h>  
using namespace std;

class Solution {
    public:
        int beautySum(string s) {
            int ans = 0;
            for (int i = 0; i < s.size(); i++) {
                unordered_map<char, int> mp;
                for (int j = i; j < s.size(); j++) {
                    int maxi = INT_MIN, mini = INT_MAX;
                    mp[s[j]]++;
                    for (auto& k : mp) {
                        maxi = max(maxi, k.second);
                        mini = min(mini, k.second);
                    }
                    ans += (maxi - mini);
                }
            }
            return ans;
        }
    };