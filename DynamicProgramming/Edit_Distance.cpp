class Solution {
    public:
        int fun(string& text1, string& text2, vector<vector<int>>& dp, int idx1,
                int idx2) {
            if (idx1 == text1.size())
                return text2.size() - idx2;
            if (idx2 == text2.size())
                return text1.size() - idx1;
            if (dp[idx1][idx2] != -1) {
                return dp[idx1][idx2];
            }
            if (text1[idx1] == text2[idx2]) {
                return dp[idx1][idx2] = fun(text1, text2, dp, idx1 + 1, idx2 + 1);
            } else {
                int a = 1 + fun(text1, text2, dp, idx1 + 1, idx2);
                int b = 1 + fun(text1, text2, dp, idx1, idx2 + 1);
                int c = 1 + fun(text1, text2, dp, idx1 + 1, idx2 + 1);
                return dp[idx1][idx2] = min({a, b, c});
            }
        }
        int minDistance(string text1, string text2) {
            vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
            int ans = fun(text1, text2, dp, 0, 0);
            return ans;
        }
    };