class Solution {
public:
    void dfs(vector<vector<int>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] == 0) {
            return;
        }
        board[i][j] = 0;
        dfs(board, i - 1, j);
        dfs(board, i, j - 1);
        dfs(board, i + 1, j);
        dfs(board, i, j + 1);
    }
    int numEnclaves(vector<vector<int>>& board) {
        int ans = 0;
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 1) {
                dfs(board, i, 0);
            }
            if (board[i][board[0].size() - 1] == 1) {
                dfs(board, i, board[0].size() - 1);
            }
        }
        for (int j = 0; j < board[0].size(); j++) {
            if (board[0][j] == 1) {
                dfs(board, 0, j);
            }
            if (board[board.size() - 1][j] == 1) {
                dfs(board, board.size() - 1, j);
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};