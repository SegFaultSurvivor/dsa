#include <bits/stdc++.h>  
using namespace std;

class Solution {
    public:
        void row(int row, vector<vector<int>>& matrix) {
            for (int i = 0; i < matrix[0].size(); i++) {
                if (matrix[row][i] != 0) {
                    matrix[row][i] = 0;
                }
            }
        }
        void col(int col, vector<vector<int>>& matrix) {
            for (int i = 0; i < matrix.size(); i++) {
                if (matrix[i][col] != 0) {
                    matrix[i][col] = 0;
                }
            }
        }
        void setZeroes(vector<vector<int>>& matrix) {
            int count = 0;
            vector<pair<int, int>> temp;
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    if (matrix[i][j] == 0) {
                        temp.push_back({i, j});
                    }
                }
            }
            for (auto& i : temp) {
                row(i.first, matrix);
                col(i.second, matrix);
            }
        }
    };