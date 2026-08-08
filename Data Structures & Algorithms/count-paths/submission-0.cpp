#include <cstring>

class Solution {
public:
    int dp[102][102];

    int paths(int i, int j, int m, int n) {
        if (i == m && j == n) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        int res = 0;

        if (i+1 <= m) {
            res += paths(i+1, j, m, n);
        }

        if (j+1 <= n) {
            res += paths(i, j+1, m, n);
        }

        return dp[i][j] = res;
    }

    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));

        return paths(0, 0, m-1, n-1);
    }
};
