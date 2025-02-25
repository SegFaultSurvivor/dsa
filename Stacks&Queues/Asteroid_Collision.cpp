class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            vector<int> ans;
            stack<int> st;
            int flag = 0;
            for (int i = asteroids.size() - 1; i >= 0; i--) {
                flag = 0;
                while (!st.empty() && st.top() < 0 && asteroids[i] > 0) {
                    if (abs(st.top()) < abs(asteroids[i])) {
                        st.pop();
                    } else {
                        flag = 1;
                        break;
                    }
                }
                if (!st.empty() && st.top() < 0 && asteroids[i] > 0 &&
                    abs(st.top()) == abs(asteroids[i])) {
                    st.pop();
                }
                if (flag != 1) {
                    st.push(asteroids[i]);
                }
            }
            while (!st.empty()) {
                ans.push_back(st.top());
                st.pop();
            }
            return ans;
        }
    };