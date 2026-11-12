class Solution {
public:
    bool isValid(string s) {
        // ( -> add to stack
        // ) -> if ( on top of stack -> pop
        //      if not -> return false

        stack<char> st;
        unordered_map<char,char> m = {
            {')', '('}, {'}', '{'}, {']', '['}
        };

        for (int i = 0; i < s.length(); i++) {
            if (m.contains(s[i])) {
                if (!st.empty() && st.top() == m[s[i]]) {
                    st.pop();
                } else return false;
            } else {
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};
