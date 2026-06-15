class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    
    MinStack() {}
    
    void push(int value) {
        st.push(value);
        minSt.push(min(value, minSt.empty() ? value : minSt.top()));
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
