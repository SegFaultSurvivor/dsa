class Solution {
    public:
        unordered_map<int, bool> dp;
        bool fun(string& s, vector<string>& wordDict, int idx) {
            if (idx == s.size())
                return true;
            if (dp.find(idx) != dp.end())
                return dp[idx];
            for (string& word : wordDict) {
                int length = word.size();
                if (idx + length <= s.size() && s.substr(idx, length) == word) {
                    if (fun(s, wordDict, idx + length)) {
                        return dp[idx] = true;
                    }
                }
            }
            return dp[idx] = false;
        }
        bool wordBreak(string s, vector<string>& wordDict) {
            return fun(s, wordDict, 0);
        }
    };
    