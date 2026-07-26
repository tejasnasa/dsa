class Solution {
public:
    int func(vector<int> &cost, int i, int n, vector<int> &dp) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        return dp[i] = (cost[i] + min(func(cost,i+1,n,dp), func(cost,i+2,n,dp)));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(102, -1);
        int n = cost.size();

        return min(func(cost,0,n,dp), func(cost,1,n,dp));
    }
};
