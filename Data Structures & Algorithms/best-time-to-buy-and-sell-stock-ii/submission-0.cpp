#include <cstring>

class Solution {
public:
    int dp[10005][2];

    int profit(vector<int> &prices, int i, int n, int buy) {
        if (i == n) return 0;

        if (dp[i][buy] != -1) return dp[i][buy];

        // dont do anything
        int res = profit(prices, i+1, n, buy);

        if (buy) {
            res = max(res, prices[i] + profit(prices, i+1, n, 0));
        } else {
            res = max(res, -prices[i] + profit(prices, i+1, n, 1));
        }

        return dp[i][buy] = res;
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));

        return profit(prices, 0, prices.size(), 0);
    }
};