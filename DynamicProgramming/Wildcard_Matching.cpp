class Solution {
    public:
        bool fun(string& s, string& p, vector<vector<int>>& dp, int idx1,
                 int idx2) {
            if (idx1 == s.size() && idx2 == p.size()) {
                return 1;
            }
            if (idx2 == p.size()) {
                return 0;
            }
            if (dp[idx1][idx2] != -1) {
                return dp[idx1][idx2];
            }
            if (idx1 < s.size() && (s[idx1] == p[idx2] || p[idx2] == '?')) {
                return dp[idx1][idx2] = fun(s, p, dp, idx1 + 1, idx2 + 1);
            } else if (p[idx2] == '*') {
                bool a = fun(s, p, dp, idx1, idx2 + 1);
                if (a == 1) {
                    return dp[idx1][idx2] = a;
                }
                bool b = 0;
                for (int i = idx1; i < s.size(); i++) {
                    b = fun(s, p, dp, i + 1, idx2 + 1);
                    if (b == 1) {
                        return dp[idx1][idx2] = b;
                    }
                }
                return dp[idx1][idx2] = 0;
            } else {
                return dp[idx1][idx2] = 0;
            }
        }
        bool isMatch(string s, string p) {
            vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
            bool ans = fun(s, p, dp, 0, 0);
            return ans;
        }
    };