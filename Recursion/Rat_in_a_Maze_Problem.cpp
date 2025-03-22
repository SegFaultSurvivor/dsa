class Solution {
    public:
        vector<string> ans;
        void fun(vector<vector<int>>& board, int i, int j, string temp) {
            if (i == board.size() - 1 && j == board[0].size() - 1) {
                ans.push_back(temp);
                return;
            }
            if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
                board[i][j] == 0) {
                return;
            }
            board[i][j] = 0;
            fun(board, i - 1, j, temp + 'U');
            fun(board, i, j - 1, temp + 'L');
            fun(board, i + 1, j, temp + 'D');
            fun(board, i, j + 1, temp + 'R');
            board[i][j] = 1;
        }
        vector<string> findPath(vector<vector<int>>& board) {
            if (board[0][0] == 0) {
                return ans;
            }
            string temp = "";
            fun(board, 0, 0, temp);
            return ans;
        }
    };