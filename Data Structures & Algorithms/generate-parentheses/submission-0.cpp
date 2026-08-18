class Solution {
public:
    vector<string> res;

    void par (int open, int close, int n, string &s) {
        if (open == close && close == n) {
            res.push_back(s);
            return;
        }

        if (open > n || close > n || close > open) return;

        s.push_back('(');
        par(open+1, close, n, s);
        s.pop_back();

        s.push_back(')');
        par(open, close+1, n, s);
        s.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        par(0, 0, n, s);

        return res;
    }
};
