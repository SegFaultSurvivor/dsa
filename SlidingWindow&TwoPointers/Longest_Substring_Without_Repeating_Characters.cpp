class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int l = 0, r = 0;
            int maxi = 0;
            unordered_map<char, int> mp;
            while (r < s.size()) {
                while (mp.find(s[r]) != mp.end()) {
                    mp[s[l]]--;
                    if (mp[s[l]] == 0) {
                        mp.erase(s[l]);
                    }
                    l++;
                }
                mp[s[r]]++;
                maxi = max(maxi, r - l + 1);
                r++;
            }
            return maxi;
        }
    };