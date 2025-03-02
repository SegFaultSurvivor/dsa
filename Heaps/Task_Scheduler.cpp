class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            priority_queue<int> pq;
            unordered_map<char, int> mp;
            int time = 0;
            for (auto& i : tasks) {
                mp[i]++;
            }
            for (auto& i : mp) {
                pq.push(i.second);
            }
            while (!pq.empty()) {
                vector<int> temp;
                for (int i = 0; i <= n; i++) {
                    if (!pq.empty()) {
                        int val = pq.top();
                        pq.pop();
                        val--;
                        temp.push_back(val);
                    }
                }
    
                for (auto& j : temp) {
                    if (j > 0) {
                        pq.push(j);
                    }
                }
                if (pq.empty()) {
                    time += temp.size();
                } else {
                    time += n + 1;
                }
            }
            return time;
        }
    };