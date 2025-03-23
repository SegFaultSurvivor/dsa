class Solution {
    public:
        bool fun(vector<vector<char>>& board) {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (board[i][j] == '.') {
                        for (char c = '1'; c <= '9'; c++) {
                            if (isValid(board, i, j, c)) {
                                board[i][j] = c;
                                if (fun(board)) {
                                    return 1;
                                } else {
                                    board[i][j] = '.';
                                }
                            }
                        }
                        return 0;
                    }
                }
            }
            return 1;
        }
        bool isValid(vector<vector<char>>& board, int row, int col, char c) {
            for (int i = 0; i < 9; i++) {
                if (board[i][col] == c) {
                    return 0;
                }
                if (board[row][i] == c) {
                    return 0;
                }
                if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
                    return 0;
                }
            }
            return 1;
        }
        void solveSudoku(vector<vector<char>>& board) { bool flag = fun(board); }
    };