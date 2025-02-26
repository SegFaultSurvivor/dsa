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
    
        int maximalRectangle(vector<vector<char>>& matrix) {
            vector<int> arr(matrix[0].size(), 0);
            vector<int> nse, pse;
            int maxi = INT_MIN;
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    arr[j] =
                        (matrix[i][j] == '0') ? 0 : (matrix[i][j] - '0') + arr[j];
                }
                nse = findNse(arr);
                pse = findPse(arr);
                for (int i = 0; i < arr.size(); i++) {
                    maxi = max(maxi, (arr[i]) * (nse[i] - pse[i] - 1));
                }
            }
            return maxi;
        }
    };