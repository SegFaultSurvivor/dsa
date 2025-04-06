class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int starting_index = 0, total_gas = 0, total_cost = 0, cur_gas = 0;
            for (int i = 0; i < gas.size(); i++) {
                total_gas += gas[i];
                total_cost += cost[i];
                cur_gas += gas[i] - cost[i];
                if (cur_gas < 0) {
                    starting_index = i + 1;
                    cur_gas = 0;
                }
            }
            return (total_gas < total_cost) ? -1 : starting_index;
        }
    };