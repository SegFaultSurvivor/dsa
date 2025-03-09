#define ll long long
class Solution {
public:
    bool fun(vector<int>& bloomDay, int mid, int k, int m) {
        int bouquets = 0, count = k;
        for (auto& i : bloomDay) {
            if (mid >= i) {
                count--;
                if (count == 0) {
                    bouquets++;
                    count = k;
                }
            } else {
                count = k;
            }
        }
        if (bouquets < m) {
            return 1;
        }
        return 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        ll flowers = (ll)m * (ll)k;
        if (flowers > bloomDay.size()) {
            return -1;
        }
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        while (l <= r) {
            int mid = (l + r) / 2;
            bool bouquets = fun(bloomDay, mid, k, m);
            if (bouquets) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};