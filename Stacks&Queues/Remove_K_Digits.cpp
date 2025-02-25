class Solution {
    public:
        string removeKdigits(string num, int k) {
            stack<char> st;
            string ans = "";
            int ptr = 0;
            for (char i : num) {
                while (!st.empty() && st.top() > i && k) {
                    st.pop();
                    k--;
                }
                st.push(i);
            }
            while (k && !st.empty()) {
                st.pop();
                k--;
            }
            while (!st.empty()) {
                ans += st.top();
                st.pop();
            }
            reverse(ans.begin(), ans.end());
            while (!ans.empty() && ans[0] == '0') {
                ans.erase(ans.begin());
            }
    
            return ans.empty() ? "0" : ans;
        }
    };