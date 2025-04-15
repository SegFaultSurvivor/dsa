class Solution {
    public:
        int fun(string& s1, string& s2, vector<vector<int>>& dp, int idx1,
                int idx2) {
            if (idx1 == s1.size() || idx2 == s2.size()) {
                return 0;
            }
            if (dp[idx1][idx2] != -1) {
                return dp[idx1][idx2];
            }
            if (s1[idx1] == s2[idx2]) {
                return dp[idx1][idx2] = 1 + fun(s1, s2, dp, idx1 + 1, idx2 + 1);
            } else {
                return dp[idx1][idx2] = max(fun(s1, s2, dp, idx1, idx2 + 1),
                                            fun(s1, s2, dp, idx1 + 1, idx2));
            }
        }
        int minInsertions(string s) {
            string s1 = s, s2 = s;
            reverse(s2.begin(), s2.end());
            vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
            int ans = fun(s1, s2, dp, 0, 0);
            return s.size() - ans;
        }
    };