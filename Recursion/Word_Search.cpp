class Solution {
    public:
        bool fun(vector<vector<char>>& board, string& word, int idx, int i, int j) {
            if (idx == word.size()) {
                return 1;
            }
            if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
                word[idx] != board[i][j]) {
                return 0;
            }
            char ch = board[i][j];
            board[i][j] = '#';
            bool top = fun(board, word, idx + 1, i - 1, j);
            bool left = fun(board, word, idx + 1, i, j - 1);
            bool down = fun(board, word, idx + 1, i + 1, j);
            bool right = fun(board, word, idx + 1, i, j + 1);
            board[i][j] = ch;
            return top || left || down || right;
        }
        bool exist(vector<vector<char>>& board, string word) {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (word[0] == board[i][j]) {
                        bool flag = fun(board, word, 0, i, j);
                        if (flag == 1) {
                            return 1;
                        }
                    }
                }
            }
            return 0;
        }
    };