class MyQueue {
    public:
        stack<int> st1, st2;
        MyQueue() {}
    
        void push(int x) {
            while (!st2.empty()) {
                st1.push(st2.top());
                st2.pop();
            }
            st1.push(x);
        }
    
        int pop() {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            int val = st2.top();
            st2.pop();
            return val;
        }
    
        int peek() {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            int val = st2.top();
            return val;
        }
    
        bool empty() {
            if (st1.size() == 0 && st2.size() == 0) {
                return 1;
            }
            return 0;
        }
    };
    
    /**
     * Your MyQueue object will be instantiated and called as such:
     * MyQueue* obj = new MyQueue();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->peek();
     * bool param_4 = obj->empty();
     */