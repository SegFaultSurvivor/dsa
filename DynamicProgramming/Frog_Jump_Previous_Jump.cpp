class Solution {
    public:
        unordered_map<int, int> mp;
        unordered_map<int, unordered_map<int, int>> dp;
        int maxi = INT_MIN;
        bool fun(int idx, int jump, vector<int>& stones) {
            if (idx > maxi) {
                return 0;
            }
            if (mp.count(idx) == 0) {
                return 0;
            }
            if (idx == maxi) {
                return 1;
            }
            if (dp[idx].count(jump) != 0) {
                return dp[idx][jump];
            }
            for (int i = jump - 1; i <= jump + 1; i++) {
                if (i > 0) {
                    bool flag = fun(idx + i, i, stones);
                    dp[idx][jump] = flag;
                    if (flag == 1) {
                        return 1;
                    }
                }
            }
            return 0;
        }
        bool canCross(vector<int>& stones) {
            for (auto& i : stones) {
                maxi = max(maxi, i);
                mp[i] = 1;
            }
            bool ans = fun(0, 0, stones);
            return ans;
        }
    };