#include <cstring>

class Solution {
public:
    int dp[10001];

    int func(vector<int> &coins, int amount) {
        if (amount == 0) return 0;
        if (dp[amount] != -1) return dp[amount];

        int mv = INT_MAX;

        for (auto c: coins) {
            if (amount >= c) {
                int sub = func(coins, amount - c);
                if (sub != INT_MAX) {
                    mv = min(mv, 1 + sub);
                }
            }
        }

        return dp[amount] = mv;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int res = func(coins, amount);
        return res == INT_MAX ? -1 : res;
    }
};
