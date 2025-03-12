class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int l = 0, r = matrix[0].size() - 1;
            while (l <= matrix.size() - 1 && r >= 0) {
                if (matrix[l][r] == target) {
                    return 1;
                } else if (matrix[l][r] > target) {
                    r--;
                } else {
                    l++;
                }
            }
            return 0;
        }
    };