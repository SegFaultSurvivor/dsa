class Solution {
public:
    int dfs(vector<vector<char>>& grid, vector<vector<char>>& vis, int i,
            int j) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() ||
            vis[i][j] == '0') {
            return 0;
        }
        vis[i][j] = '0';
        int top = dfs(grid, vis, i - 1, j);
        int left = dfs(grid, vis, i, j - 1);
        int down = dfs(grid, vis, i + 1, j);
        int right = dfs(grid, vis, i, j + 1);
        return top + left + down + right + 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<char>> vis = grid;
        int ans = 0;
        unordered_set<int> st;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && vis[i][j] == '1') {
                    int len = dfs(grid, vis, i, j);
                    st.insert(len);
                    ans++;
                }
            }
        }
        for (auto& i : st) {
            cout << i << endl;
        }
        return ans;
    }
};