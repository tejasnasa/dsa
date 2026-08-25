class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for (auto a: asteroids) {
            int alive = true;

            while (alive && !st.empty() && st.top() > 0 && a < 0) {
                if (abs(st.top()) < abs(a)) {
                    st.pop();
                } else if (abs(st.top()) == abs(a)) {
                    st.pop();
                    alive = false;
                } else {
                    alive = false;
                }
            }

            if (alive) st.push(a);
        }

        vector<int> res;

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};