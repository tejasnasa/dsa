class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> res(temperatures.size(),0);
        st.push({0,temperatures[0]});

        for (int i = 1; i < temperatures.size(); i++) {
            while (!st.empty() && st.top().second < temperatures[i]) {
                cout << st.top().second << " ";
                res[st.top().first] = (i - st.top().first);
                st.pop(); 
            }

            st.push({i,temperatures[i]});
        }

        return res;
    }
};
