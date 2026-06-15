class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> m = {{')','('},{'}','{'},{']','['}};
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (m.count(s[i])) {
                if (!st.empty() && st.top() == m[s[i]]) {
                    st.pop();
                } else return false;
            } else {
                st.push(s[i]);
            }
        }

        return (st.empty());
    }
};
