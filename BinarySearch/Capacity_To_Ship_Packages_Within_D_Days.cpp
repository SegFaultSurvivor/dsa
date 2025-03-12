class Solution {
    public:
        bool fun(vector<int>& weights, int days, int mid) {
            int cur_days = 1, sum = 0;
            for (auto& i : weights) {
                sum += i;
                if (sum > mid) {
                    cur_days++;
                    sum = i;
                }
            }
            if (cur_days <= days) {
                return 1;
            }
            return 0;
        }
        int shipWithinDays(vector<int>& weights, int days) {
            int l = *max_element(weights.begin(), weights.end());
            int r = accumulate(weights.begin(), weights.end(), 0);
            while (l <= r) {
                int mid = (l + r) / 2;
                bool cur_days = fun(weights, days, mid);
                if (cur_days) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        }
    };