class StockSpanner {
public:
    stack<int> st;
    vector<int> popped;
        
    StockSpanner() {

    }
    
    int next(int price) {
        int count = 1;

        while (!st.empty() && st.top() <= price) {
            count++;
            popped.push_back(st.top());
            st.pop();
        }

        for (int i = 0; i < popped.size(); i++) {
            st.push(popped[i]);
        }

        st.push(price);
        popped.clear();

        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */