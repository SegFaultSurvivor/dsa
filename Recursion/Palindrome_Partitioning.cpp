class Solution {
    public:
        vector<vector<string>> ans;
        bool isPalindrome(string& s, int start, int end) {
            for (int i = start, j = end; i < j; i++, j--) {
                if (s[i] != s[j]) {
                    return 0;
                }
            }
            return 1;
        }
        void fun(string& s, int idx, vector<string>& temp) {
            if (idx == s.size()) {
                ans.push_back(temp);
                return;
            }
            for (int i = idx; i < s.size(); i++) {
                if (isPalindrome(s, idx, i)) {
                    temp.push_back(s.substr(idx, i - idx + 1));
                    fun(s, i + 1, temp);
                    temp.pop_back();
                }
            }
        }
        vector<vector<string>> partition(string s) {
            vector<string> temp;
            fun(s, 0, temp);
            return ans;
        }
    };