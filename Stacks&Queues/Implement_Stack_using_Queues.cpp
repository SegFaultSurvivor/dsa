class MyStack {
    public:
        queue<int> q;
        MyStack() {}
    
        void push(int x) {
            int len = q.size();
            q.push(x);
            for (int i = 0; i < len; i++) {
                int val = q.front();
                q.pop();
                q.push(val);
            }
        }
    
        int pop() {
            int val = q.front();
            q.pop();
            return val;
        }
    
        int top() { return q.front(); }
    
        bool empty() { return (q.size() == 0) ? 1 : 0; }
    };
    
    /**
     * Your MyStack object will be instantiated and called as such:
     * MyStack* obj = new MyStack();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->top();
     * bool param_4 = obj->empty();
     */