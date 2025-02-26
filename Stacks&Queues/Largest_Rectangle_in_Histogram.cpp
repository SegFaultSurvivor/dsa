class Solution {
    public:
        vector<int> findNse(vector<int>& arr) {
            vector<int> nse(arr.size(), arr.size());
            stack<int> st;
            for (int i = arr.size() - 1; i >= 0; i--) {
                while (!st.empty() && arr[st.top()] >= arr[i]) {
                    st.pop();
                }
                if (!st.empty()) {
                    nse[i] = st.top();
                }
                st.push(i);
            }
            return nse;
        }
    
        vector<int> findPse(vector<int>& arr) {
            vector<int> pse(arr.size(), -1);
            stack<int> st;
            for (int i = 0; i < arr.size(); i++) {
                while (!st.empty() && arr[st.top()] > arr[i]) {
                    st.pop();
                }
                if (!st.empty()) {
                    pse[i] = st.top();
                }
                st.push(i);
            }
            return pse;
        }
    
        int largestRectangleArea(vector<int>& heights) {
            int maxi = INT_MIN;
            vector<int> nse, pse;
            nse = findNse(heights);
            pse = findPse(heights);
            for (int i = 0; i < heights.size(); i++) {
                maxi = max(maxi, heights[i] * (nse[i] - pse[i] - 1));
            }
            return maxi;
        }
    };