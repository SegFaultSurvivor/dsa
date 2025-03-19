class Solution {
    public:
        vector<string> ans;
        void fun(string temp, int open, int close) {
            if (open < 0 || close < 0) {
                return;
            }
            if (open == 0 && close == 0) {
                ans.push_back(temp);
                return;
            }
            fun(temp + '(', open - 1, close);
            if (close > open) {
                fun(temp + ')', open, close - 1);
            }
        }
        vector<string> generateParenthesis(int n) {
            fun("", n, n);
            return ans;
        }
    };
    