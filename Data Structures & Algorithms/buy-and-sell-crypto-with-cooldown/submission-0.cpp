#include <cstring>

class Solution {
public:
    int dp[5005][2];

    int profit(vector<int> &prices, int i, int n, bool buying) {
        if (i >= n) return 0;

        if (dp[i][buying] != -1) return dp[i][buying];

        int cooldown = profit(prices, i+1, n, buying);
        if (buying) {
            int buy = profit(prices, i+1, n, false) - prices[i];
            return dp[i][buying] = max(buy, cooldown);
        } else {
            int sell = profit(prices, i+2, n, true) + prices[i];
            return dp[i][buying] = max(sell, cooldown);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));

        return profit(prices, 0, n, true);
    }
};
