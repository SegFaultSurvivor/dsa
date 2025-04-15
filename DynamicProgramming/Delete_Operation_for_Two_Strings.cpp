class Solution {
    public:
        int fun(string& word1, string& word2, int idx1, int idx2,
                vector<vector<int>>& dp) {
            if (idx1 == word1.size()) {
                return word2.size() - idx2;
            }
            if (idx2 == word2.size()) {
                return word1.size() - idx1;
            }
            if (dp[idx1][idx2] != -1) {
                return dp[idx1][idx2];
            }
            if (word1[idx1] == word2[idx2]) {
                return dp[idx1][idx2] = fun(word1, word2, idx1 + 1, idx2 + 1, dp);
            } else {
                return dp[idx1][idx2] =
                           min(1 + fun(word1, word2, idx1 + 1, idx2, dp),
                               1 + fun(word1, word2, idx1, idx2 + 1, dp));
            }
        }
        int minDistance(string word1, string word2) {
            vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
            int ans = fun(word1, word2, 0, 0, dp);
            return ans;
        }
    };