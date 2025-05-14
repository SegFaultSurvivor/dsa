class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> vis = mat;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 0;
                } else {
                    vis[i][j] = -1;
                }
            }
        }
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto node = q.front();
                q.pop();
                int row = node.first;
                int col = node.second;
                for (auto& i : dir) {
                    int temp_row = row + i.first;
                    int temp_col = col + i.second;
                    if (temp_row >= 0 && temp_row < mat.size() &&
                        temp_col >= 0 && temp_col < mat[0].size() &&
                        vis[temp_row][temp_col] == -1) {
                        vis[temp_row][temp_col] = vis[row][col] + 1;
                        q.push({temp_row, temp_col});
                    }
                }
            }
        }
        return vis;
    }
};