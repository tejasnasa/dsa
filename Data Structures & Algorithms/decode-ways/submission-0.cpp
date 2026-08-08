#include <cstring>

class Solution {
public:
    int dp[102];

    int dfs(string &s, int i, int n) {
        if (i == n) return 1;
        if (i > n) return 0;
        if (dp[i] != -1) return dp[i];

        int res = 0;

        if (i+2 <= n && (s[i] == '1' || (s[i] == '2' && s[i+1]-'0' <= 6))) {
            cout << "a" << s[i] << endl;
            res = dfs(s, i+2, n) + dfs(s, i+1, n);
        } else if (s[i] != '0') {
            cout << "b" << s[i] << endl;
            res = dfs(s, i+1, n);
        }

        return dp[i] = res;
    }

    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.length();

        return dfs(s, 0, n);
    }
};
