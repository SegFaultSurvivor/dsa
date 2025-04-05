class Solution {
    public:
        int findPlatform(vector<int>& arr, vector<int>& dep) {
            sort(arr.begin(), arr.end());
            sort(dep.begin(), dep.end());
            int i = 0, j = 0;
            int platform = 0, maxi = 0;
            while (i < arr.size() && j < arr.size()) {
                if (arr[i] <= dep[j]) {
                    platform++;
                    maxi = max(maxi, platform);
                    i++;
                } else {
                    platform--;
                    j++;
                }
            }
            return maxi;
        }
    };