class Solution {
    public:
        vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
            int maxi = *max_element(deadline.begin(), deadline.end());
            vector<int> temp(maxi + 1, -1);
            vector<pair<int, int>> time_line;
            for (int i = 0; i < profit.size(); i++) {
                time_line.push_back({profit[i], deadline[i]});
            }
            sort(time_line.begin(), time_line.end(),
                 [](auto& a, auto& b) { return a.first > b.first; });
            int jobs = 0, max_profit = 0;
            for (int i = 0; i < time_line.size(); i++) {
                int p = time_line[i].first;
                int d = time_line[i].second;
                while (d > 0 && temp[d] != -1) {
                    d--;
                }
                if (d > 0) {
                    temp[d] = 1;
                    jobs++;
                    max_profit += p;
                }
            }
            return {jobs, max_profit};
        }
    };