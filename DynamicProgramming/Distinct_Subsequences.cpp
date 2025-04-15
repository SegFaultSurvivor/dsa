class Solution {
    public:
        int fun(string& text1, string& text2, vector<vector<int>>& dp, int idx1,
                int idx2) {
            if (idx2 == text2.size()) {
                return 1;
            }
            if (idx1 == text1.size()) {
                return 0;
            }
            if (dp[idx1][idx2] != -1) {
                return dp[idx1][idx2];
            }
            int a = 0;
            if (text1[idx1] == text2[idx2]) {
                a = fun(text1, text2, dp, idx1 + 1, idx2 + 1);
            }
            int b = fun(text1, text2, dp, idx1 + 1, idx2);
            return dp[idx1][idx2] = a + b;
        }
        int numDistinct(string text1, string text2) {
            vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
            int ans = fun(text1, text2, dp, 0, 0);
            return ans;
        }
    };