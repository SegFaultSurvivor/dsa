class Solution {
    public:
        bool isPalindrome(string& s, int i, int j, vector<vector<int>>& dp) {
            if (i >= j) {
                return 1;
            }
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            if (s[i] == s[j]) {
                return dp[i][j] = isPalindrome(s, i + 1, j - 1, dp);
            }
            return dp[i][j] = 0;
        }
        string longestPalindrome(string s) {
            vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
            int index = -1;
            int maxi_len = INT_MIN;
            for (int i = 0; i < s.size(); i++) {
                for (int j = i; j < s.size(); j++) {
                    if (isPalindrome(s, i, j, dp)) {
                        if (j - i + 1 > maxi_len) {
                            maxi_len = j - i + 1;
                            index = i;
                        }
                    }
                }
            }
            return s.substr(index, maxi_len);
        }
    };