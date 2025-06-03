class Solution {
public:
    void dfs(vector<vector<int>>& stones, int idx, vector<int>& vis) {
        vis[idx] = 1;
        for (int i = 0; i < stones.size(); i++) {
            int r = stones[i][0];
            int c = stones[i][1];
            if (vis[i] == -1 && (stones[idx][0] == r || stones[idx][1] == c)) {
                dfs(stones, i, vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        vector<int> vis(stones.size(), -1);
        int count = 0;
        for (int i = 0; i < stones.size(); i++) {
            if (vis[i] == -1) {
                dfs(stones, i, vis);
                count++;
            }
        }
        return stones.size() - count;
    }
};