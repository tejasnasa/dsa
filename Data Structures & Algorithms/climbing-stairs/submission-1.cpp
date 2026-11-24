#include <cstring>
class Solution {
public:
    int dp[50];

    int dfs(int i, int n) {
        if (i >= n) return i == n;
        if (dp[i] != -1) return dp[i];

        return dp[i] = dfs(i+1,n) + dfs(i+2,n);
    }

    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return dfs(0,n);
    }
};
