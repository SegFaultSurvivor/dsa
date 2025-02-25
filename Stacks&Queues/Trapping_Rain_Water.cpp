class Solution {
    public:
        int trap(vector<int>& height) {
            vector<int> left(height.size(), -1), right(height.size(), -1);
            int ans = 0;
            left[0] = height[0];
            int maxi = left[0];
            for (int i = 1; i < height.size(); i++) {
                if (maxi > height[i]) {
                    left[i] = maxi;
                } else {
                    left[i] = height[i];
                    maxi = max(maxi, height[i]);
                }
            }
            right[height.size() - 1] = height[height.size() - 1];
            maxi = right[height.size() - 1];
            for (int i = height.size() - 2; i >= 0; i--) {
                if (maxi > height[i]) {
                    right[i] = maxi;
                } else {
                    right[i] = height[i];
                    maxi = max(maxi, height[i]);
                }
            }
            for (int i = 0; i < height.size(); i++) {
                ans += min(left[i], right[i]) - height[i];
            }
            return ans;
        }
    };