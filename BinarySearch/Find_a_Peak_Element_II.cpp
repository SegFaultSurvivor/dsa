class Solution {
    public:
        vector<int> fun(vector<vector<int>>& mat, int mid) {
            int maxi = INT_MIN;
            vector<int> temp(2, mid);
            for (int i = 0; i < mat.size(); i++) {
                if (maxi < mat[i][mid]) {
                    maxi = mat[i][mid];
                    temp[0] = i;
                }
            }
            return temp;
        }
        vector<int> findPeakGrid(vector<vector<int>>& mat) {
            int l = 0, r = mat[0].size() - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                vector<int> temp = fun(mat, mid);
                int cur_value = mat[temp[0]][temp[1]];
                if ((mid == 0 || cur_value > mat[temp[0]][mid - 1]) &&
                    (mid == mat[0].size() - 1 ||
                     cur_value > mat[temp[0]][mid + 1])) {
                    return temp;
                } else if (mid > 0 && mat[temp[0]][mid - 1] > cur_value) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            return {-1, -1};
        }
    };