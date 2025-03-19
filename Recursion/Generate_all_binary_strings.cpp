class Solution {
    public:
        vector<string> ans;
        void fun(int num, string temp) {
            if (num == 0) {
                ans.push_back(temp);
                return;
            }
            fun(num - 1, temp + '0');
            if (temp[temp.size() - 1] != '1') {
                fun(num - 1, temp + '1');
            }
        }
        vector<string> generateBinaryStrings(int num) {
            fun(num, "");
            return ans;
        }
    };