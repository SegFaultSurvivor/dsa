class Solution {
    public:
        bool fun(string& s, int idx, int open, int close,
                 vector<vector<vector<int>>>& dp) {
            if (close > open) {
                return 0;
            }
            if (idx == s.size()) {
                return open == close;
            }
            if (dp[idx][open][close] != -1) {
                return dp[idx][open][close];
            }
            if (s[idx] == '(') {
                return dp[idx][open][close] = fun(s, idx + 1, open + 1, close, dp);
            } else if (s[idx] == ')') {
                return dp[idx][open][close] = fun(s, idx + 1, open, close + 1, dp);
            } else {
                return dp[idx][open][close] =
                           (fun(s, idx + 1, open + 1, close, dp) ||
                            fun(s, idx + 1, open, close + 1, dp) ||
                            fun(s, idx + 1, open, close, dp));
            }
        }
        bool checkValidString(string s) {
            vector<vector<vector<int>>> dp(
                s.size() + 1,
                vector<vector<int>>(s.size() + 1, vector<int>(s.size() + 1, -1)));
            bool flag = fun(s, 0, 0, 0, dp);
            return flag;
        }
    };