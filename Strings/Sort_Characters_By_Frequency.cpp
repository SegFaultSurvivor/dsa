#include <bits/stdc++.h>  
using namespace std;

class Solution {
    public:
        string frequencySort(string s) {
            unordered_map<char, int> mp;
            string res = "";
            for (auto& i : s) {
                mp[i]++;
            }
            vector<pair<int, int>> ans;
            for (auto& i : mp) {
                ans.push_back({i.second, i.first});
            }
            sort(ans.begin(), ans.end(),
                 [](auto& a, auto& b) { return a.first > b.first; });
            for (auto& i : ans) {
                for (int j = 0; j < i.first; j++) {
                    res += i.second;
                }
            }
            return res;
        }
    };