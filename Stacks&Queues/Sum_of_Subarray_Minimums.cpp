#define MOD 1000000007
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
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int ans = 0;
        vector<int> nse, pse;
        nse = findNse(arr);
        pse = findPse(arr);
        for (int i = 0; i < arr.size(); i++) {
            nse[i] = nse[i] - i;
            pse[i] = i - pse[i];
            long long temp = (1LL * arr[i] * nse[i]) % MOD;
            temp = (temp * pse[i]) % MOD;
            ans = (ans + temp) % MOD;
        }
        return ans;
    }
};