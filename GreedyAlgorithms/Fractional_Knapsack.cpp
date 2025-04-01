class Solution {
    public:
        double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
            vector<pair<double, pair<int, int>>> temp;
            for (int i = 0; i < val.size(); i++) {
                double w_v = ((double)val[i] / wt[i]);
                temp.push_back({w_v, {val[i], wt[i]}});
            }
            sort(temp.begin(), temp.end(),
                 [](auto& a, auto& b) { return a.first > b.first; });
            double maxi = 0.0;
            int W = capacity;
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i].second.second > W) {
                    maxi += W * temp[i].first;
                    break;
                } else {
                    maxi += temp[i].second.first;
                    W -= temp[i].second.second;
                }
            }
            return maxi;
        }
    };