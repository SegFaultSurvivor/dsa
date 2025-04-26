class Solution {
    public:
        bool isSubSeq(string& s, string& t) {
            int i = 0, j = 0;
            while (i < s.size() && j < t.size()) {
                if (s[i] == t[j]) {
                    i++;
                }
                if (i == s.size()) {
                    return 1;
                }
                j++;
            }
            return 0;
        }
    
        int fun(vector<string>& words, vector<int>& dp, int idx, int prev_idx) {
            if (idx == words.size()) {
                return 0;
            }
            if (dp[prev_idx + 1] != -1) {
                return dp[prev_idx + 1];
            }
    
            int take = 0;
            if (prev_idx == -1 || words[idx].size() - words[prev_idx].size() == 1) {
                if (prev_idx == -1 || isSubSeq(words[prev_idx], words[idx])) {
                    take = 1 + fun(words, dp, idx + 1, idx);
                }
            }
    
            int not_take = fun(words, dp, idx + 1, prev_idx);
    
            return dp[prev_idx + 1] = max(take, not_take);
        }
    
        int longestStrChain(vector<string>& words) {
            sort(words.begin(), words.end(),
                 [](string& a, string& b) { return a.size() < b.size(); });
            vector<int> dp(words.size() + 1, -1);
            int ans = fun(words, dp, 0, -1);
            return ans;
        }
    };
    