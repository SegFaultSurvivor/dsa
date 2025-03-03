class Solution {
    public:
        int maxScore(vector<int>& cardPoints, int k) {
            int sum = 0, maxi = INT_MIN;
            for (int i = 0; i < k; i++) {
                sum += cardPoints[i];
            }
            maxi = max(maxi, sum);
            int j = cardPoints.size() - 1;
            for (int i = k - 1; i >= 0; i--) {
                sum = sum - cardPoints[i] + cardPoints[j--];
                maxi = max(maxi, sum);
            }
            return maxi;
        }
    };