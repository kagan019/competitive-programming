class MinStack {
public:
    vector<int> stack;
    int m;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        m = (stack.size() == 0 || x < m) ? x : m;
        stack.push_back(x);
    }
    
    void pop() {
        int t = this->top();
        stack.pop_back();
        if (t == m && stack.size()) {
            m = stack[0];
            for (int x : stack) {
                m = (x < m) ? x : m;
            }
        }
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
