#include <cstring>

class Solution {
public:
    int dp[1005][1005];

    int lcs(string s, int m, string t, int n) {
        if (m == 0 || n == 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];

        if (s[m-1] == t[n-1]) {
            return dp[m][n] = 1 + lcs(s, m-1, t, n-1);
        } else {
            return dp[m][n] = max(lcs(s, m-1, t, n), lcs(s, m, t, n-1));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));

        return lcs(text1, text1.size(), text2, text2.size());        
    }
};
