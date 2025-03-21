class Solution {
    public:
        unordered_map<int, string> mp;
        vector<string> ans;
        void fun(string& digits, int idx, string& temp) {
            if (idx == digits.size()) {
                ans.push_back(temp);
                return;
            }
            string cur_str = mp[digits[idx] - '0'];
            for (int i = 0; i < cur_str.size(); i++) {
                temp += cur_str[i];
                fun(digits, idx + 1, temp);
                temp.pop_back();
            }
        }
        vector<string> letterCombinations(string digits) {
            if (digits.size() == 0) {
                return {};
            }
            mp[2] = "abc";
            mp[3] = "def";
            mp[4] = "ghi";
            mp[5] = "jkl";
            mp[6] = "mno";
            mp[7] = "pqrs";
            mp[8] = "tuv";
            mp[9] = "wxyz";
            string temp = "";
            fun(digits, 0, temp);
            return ans;
        }
    };