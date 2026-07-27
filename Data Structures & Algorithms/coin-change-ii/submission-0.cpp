#include <cstring>

class Solution {
public:
    int dp[102][5002];

    int func(vector<int> &coins, int n, int amount) {
        if (n == 0) return 0;
        if (amount == 0) return 1;
        if (dp[n][amount] != -1) return dp[n][amount];

        if (amount >= coins[n-1]) {
            return dp[n][amount] = func(coins, n, amount-coins[n-1]) + func(coins, n-1, amount);
        } else {
            return dp[n][amount] = func(coins, n-1, amount);
        }
    }

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return func(coins, coins.size(), amount);
    }
};
