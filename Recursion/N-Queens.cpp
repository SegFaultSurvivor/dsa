class Solution {
    public:
        vector<vector<string>> ans;
        bool isValid(vector<string>& chessBoard, int row, int col) {
            int temp_row = row, temp_col = col;
            while (temp_row >= 0 && temp_col >= 0) {
                if (chessBoard[temp_row][temp_col] == 'Q') {
                    return 0;
                }
                temp_row--;
                temp_col--;
            }
            temp_row = row;
            temp_col = col;
            while (temp_row >= 0) {
                if (chessBoard[temp_row][temp_col] == 'Q') {
                    return 0;
                }
                temp_row--;
            }
            temp_row = row;
            while (temp_row >= 0 && temp_col < chessBoard[0].size()) {
                if (chessBoard[temp_row][temp_col] == 'Q') {
                    return 0;
                }
                temp_row--;
                temp_col++;
            }
            return 1;
        }
        void fun(vector<string>& chessBoard, int row) {
            if (row == chessBoard.size()) {
                ans.push_back(chessBoard);
                return;
            }
            for (int col = 0; col < chessBoard[0].size(); col++) {
                if (isValid(chessBoard, row, col)) {
                    chessBoard[row][col] = 'Q';
                    fun(chessBoard, row + 1);
                    chessBoard[row][col] = '.';
                }
            }
        }
        vector<vector<string>> solveNQueens(int n) {
            vector<string> chessBoard(n, string(n, '.'));
            fun(chessBoard, 0);
            return ans;
        }
    };