class Solution {
    public:
        bool isPalindrome(string& s, int i, int j, vector<vector<int>>& dp1) {
            if (i >= j) {
                return 1;
            }
            if (dp1[i][j] != -1) {
                return dp1[i][j];
            }
            if (s[i] == s[j]) {
                return dp1[i][j] = isPalindrome(s, i + 1, j - 1, dp1);
            }
            return dp1[i][j] = 0;
        }
        int fun(string& s, int start, vector<vector<int>>& dp1, vector<int>& dp2) {
            if (start == s.size()) {
                return -1;
            }
            if (dp2[start] != -1) {
                return dp2[start];
            }
            int mini = INT_MAX;
            for (int i = start; i < s.size(); i++) {
                if (isPalindrome(s, start, i, dp1)) {
                    int res = 1 + fun(s, i + 1, dp1, dp2);
                    mini = min(mini, res);
                }
            }
            return dp2[start] = mini;
        }
        int minCut(string s) {
            vector<vector<int>> dp1(s.size(), vector<int>(s.size(), -1));
            vector<int> dp2(s.size(), -1);
            int ans = fun(s, 0, dp1, dp2);
            return ans;
        }
    };