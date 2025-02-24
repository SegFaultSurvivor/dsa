class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
            for (auto& i : s) {
                if (i == '(' || i == '{' || i == '[') {
                    st.push(i);
                } else {
                    if (!st.empty()) {
                        char ch = st.top();
                        if (i == ')' && ch == '(' || i == '}' && ch == '{' ||
                            i == ']' && ch == '[') {
                            st.pop();
                        } else {
                            return 0;
                        }
                    } else {
                        return 0;
                    }
                }
            }
            return (st.empty()) ? 1 : 0;
        }
    };