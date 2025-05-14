class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<char>>& vis, int i,
             int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            vis[i][j] == 'X' || vis[i][j] == '#') {
            return;
        }
        vis[i][j] = '#';
        dfs(board, vis, i - 1, j);
        dfs(board, vis, i, j - 1);
        dfs(board, vis, i + 1, j);
        dfs(board, vis, i, j + 1);
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<char>> vis = board;
        for (int i = 0; i < board.size(); i++) {
            if (vis[i][0] == 'O') {
                dfs(board, vis, i, 0);
            }
            if (vis[i][board[0].size() - 1] == 'O') {
                dfs(board, vis, i, board[0].size() - 1);
            }
        }
        for (int j = 0; j < board[0].size(); j++) {
            if (vis[0][j] == 'O') {
                dfs(board, vis, 0, j);
            }
            if (vis[board.size() - 1][j] == 'O') {
                dfs(board, vis, board.size() - 1, j);
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (vis[i][j] == 'O') {
                    vis[i][j] = 'X';
                }
                if (vis[i][j] == '#') {
                    vis[i][j] = 'O';
                }
            }
        }
        board = vis;
    }
};