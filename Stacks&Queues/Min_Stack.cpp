class MinStack {
    public:
        stack<int> st1, st2, st3;
        MinStack() {}
    
        void push(int val) {
            st3.push(val);
            while (!st1.empty()) {
                int value = st1.top();
                if (val > value) {
                    st2.push(value);
                    st1.pop();
                } else {
                    break;
                }
            }
            st1.push(val);
            while (!st2.empty()) {
                st1.push(st2.top());
                st2.pop();
            }
        }
    
        void pop() {
            int val = st3.top();
            st3.pop();
            while (!st1.empty()) {
                int value = st1.top();
                if (value == val) {
                    st1.pop();
                    break;
                } else {
                    st2.push(st1.top());
                    st1.pop();
                }
            }
            while (!st2.empty()) {
                st1.push(st2.top());
                st2.pop();
            }
        }
    
        int top() { return st3.top(); }
    
        int getMin() { return st1.top(); }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */