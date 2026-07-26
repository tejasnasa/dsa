#include <cstring>

class Solution {
public:
    int dp[102];

    int func(vector<int> &cost, int i, int n) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        return dp[i] = cost[i] + min(func(cost,i+1,n), func(cost,i+2,n));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        int n = cost.size();

        return min(func(cost, 0, n), func(cost,1,n));
    }
};
