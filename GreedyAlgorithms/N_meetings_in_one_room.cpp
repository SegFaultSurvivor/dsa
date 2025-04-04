class Solution {
    public:
        int maxMeetings(vector<int>& start, vector<int>& end) {
            vector<pair<int, int>> time;
            for (int i = 0; i < start.size(); i++) {
                time.push_back({end[i], start[i]});
            }
            sort(time.begin(), time.end());
            int ans = 0, freeTime = -1;
            for (auto& i : time) {
                if (i.second > freeTime) {
                    ans++;
                    freeTime = i.first;
                }
            }
            return ans;
        }
    };