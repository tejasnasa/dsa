#include <cstring>

class Solution {
public:
    int dp[1005][1005];

    bool pal(string &s, int i, int j) {
        if (i>=j) return true;
        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = (s[i] == s[j] && pal(s, i+1, j-1));
    }

    int countSubstrings(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.length();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pal(s,i,j);
            }
        }

        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (dp[i][j]) {
                    res++;
                }
            }
        }

        return res;
    }
};
