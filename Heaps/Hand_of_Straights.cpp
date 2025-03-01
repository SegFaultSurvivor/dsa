class Solution {
    public:
        bool isNStraightHand(vector<int>& hand, int groupSize) {
            if (hand.size() % groupSize != 0) {
                return 0;
            }
            map<int, int> mp;
            for (auto& i : hand) {
                mp[i]++;
            }
            while (mp.size() != 0) {
                int value = mp.begin()->first;
                for (int i = 0; i < groupSize; i++) {
                    if (mp.find(i + value) == mp.end()) {
                        return 0;
                    } else if (mp[i + value] > 0) {
                        mp[i + value]--;
                        if (mp[i + value] == 0) {
                            mp.erase(i + value);
                        }
                    }
                }
            }
            return 1;
        }
    };