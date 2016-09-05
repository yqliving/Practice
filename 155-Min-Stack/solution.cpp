class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s1, s2;
    
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push_back(x);
        if (s2.empty() || x <= getMin())
        s2.push_back(x);
        
    }
    
    void pop() {
        int p = s1.top();
        s1.pop();
        if (p == getMin()) s2.pop;
        
    }
    
    int top() {
        return s1.top();
        
    }
    
    int getMin() {
        return s2.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
 