#define ll long long
class Solution {
public:
    bool fun(vector<int>& piles, int mid, int h) {
        ll timeTaken = 0;
        for (auto& i : piles) {
            if (mid >= i) {
                timeTaken++;
            } else {
                timeTaken += ceil((double)i / mid);
            }
        }
        if (timeTaken <= h) {
            return 1;
        }
        return 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        int l = 1, r = maxi;
        while (l <= r) {
            int mid = (l + r) / 2;
            bool timeTaken = fun(piles, mid, h);
            if (timeTaken) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};