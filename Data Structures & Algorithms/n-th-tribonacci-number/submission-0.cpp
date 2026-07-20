class Solution {
public:
    

    int t(int n, vector<int> &dp) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        if (dp[n] != -1) return dp[n];

        return dp[n] = t(n-1,dp) + t(n-2,dp) + t(n-3,dp);
    }

    int tribonacci(int n) {
        vector<int> dp(38,-1);

        return t(n, dp);
    }
};