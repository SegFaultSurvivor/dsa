class Solution {
    public:
        priority_queue<int> maxheap;
        priority_queue<int, vector<int>, greater<int>> minheap;
    
        void addNum(int num) {
            maxheap.push(num);
            minheap.push(maxheap.top());
            maxheap.pop();
            if (maxheap.size() < minheap.size()) {
                maxheap.push(minheap.top());
                minheap.pop();
            }
        }
    
        double findMedian() {
            if (maxheap.size() == minheap.size()) {
                return (double)(maxheap.top() + minheap.top()) / 2;
            }
            return maxheap.top();
        }
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            for (auto& i : nums1) {
                addNum(i);
            }
            for (auto& i : nums2) {
                addNum(i);
            }
            return findMedian();
        }
    };
    