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

    vector<int> findNge(vector<int>& arr) {
        vector<int> nge(arr.size(), arr.size());
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(i);
        }
        return nge;
    }

    vector<int> findPge(vector<int>& arr) {
        vector<int> pge(arr.size(), -1);
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pge[i] = st.top();
            }
            st.push(i);
        }
        return pge;
    }

    long long subArrayRanges(vector<int>& arr) {
        long long mini = 0, maxi = 0;
        vector<int> nse, pse, nge, pge;
        nse = findNse(arr);
        pse = findPse(arr);
        nge = findNge(arr);
        pge = findPge(arr);

        for (int i = 0; i < arr.size(); i++) {
            nse[i] = nse[i] - i;
            pse[i] = i - pse[i];
            nge[i] = nge[i] - i;
            pge[i] = i - pge[i];

            long long temp1 = 1LL * arr[i] * nse[i] * pse[i];
            mini += temp1;

            long long temp2 = 1LL * arr[i] * nge[i] * pge[i];
            maxi += temp2;
        }
        return (maxi - mini);
    }
};
