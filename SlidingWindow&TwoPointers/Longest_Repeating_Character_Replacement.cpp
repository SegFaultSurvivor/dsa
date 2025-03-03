class Solution {
    public:
        int characterReplacement(string s, int k) {
            int l = 0, r = 0;
            int maxi = 0;
            int maxfreq = INT_MIN;
            unordered_map<char, int> mp;
            while (r < s.size()) {
                mp[s[r]]++;
                for (auto& i : mp) {
                    maxfreq = max(maxfreq, i.second);
                }
                while ((r - l + 1) - maxfreq > k) {
                    mp[s[l]]--;
                    maxfreq = INT_MIN;
                    for (auto& i : mp) {
                        maxfreq = max(maxfreq, i.second);
                    }
                    l++;
                }
                maxi = max(r - l + 1, maxi);
                r++;
            }
            return maxi;
        }
    };