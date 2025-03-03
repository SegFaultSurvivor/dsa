class Solution {
    public:
        string minWindow(string s, string t) {
            int l = 0, r = 0, mini = INT_MAX, count = t.size(), s_index = -1;
            unordered_map<char, int> mp;
            for (auto& i : t) {
                mp[i]++;
            }
            count = t.size();
            while (r < s.size()) {
                if (mp.find(s[r]) == mp.end()) {
                    mp[s[r]] = -1;
                } else {
                    if (mp[s[r]] > 0) {
                        count--;
                    }
                    mp[s[r]]--;
                    while (count == 0) {
                        if (mini > (r - l + 1)) {
                            mini = r - l + 1;
                            s_index = l;
                        }
                        mp[s[l]]++;
                        if (mp[s[l]] > 0) {
                            count++;
                        }
                        l++;
                    }
                }
                r++;
            }
            return (s_index == -1) ? "" : s.substr(s_index, mini);
        }
    };