class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            vector<int> temp = nums;
            reverse(temp.begin(), temp.end());
            stack<int> st;
            for (auto& i : temp) {
                st.push(i);
            }
            for (int i = nums.size() - 1; i >= 0; i--) {
                while (!st.empty() && st.top() <= nums[i]) {
                    st.pop();
                }
                if (!st.empty()) {
                    temp[i] = st.top();
                } else {
                    temp[i] = -1;
                }
                st.push(nums[i]);
            }
            return temp;
        }
    };
    