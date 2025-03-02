class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> mp;
            priority_queue<pair<int, int>> pq;
            vector<int> ans;
            for (auto& i : nums) {
                mp[i]++;
            }
            for (auto& i : mp) {
                pq.push({i.second, i.first});
            }
            while (k) {
                auto ptr = pq.top();
                int value = ptr.second;
                ans.push_back(value);
                k--;
                pq.pop();
            }
            return ans;
        }
    };