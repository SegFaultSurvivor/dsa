#define mod 100000
class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<int> q;
        vector<int> vis(99999, 0);
        vis[start] = 1;
        q.push(start);
        int step = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                int node = q.front();
                q.pop();
                if (node == end) {
                    return step;
                }
                for (auto& i : arr) {
                    int value = (node * i) % mod;
                    if (vis[value] == 0) {
                        q.push(value);
                        vis[value] = 1;
                    }
                }
            }
            step++;
        }
        return -1;
    }
};