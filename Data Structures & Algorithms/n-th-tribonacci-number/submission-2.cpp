class Solution {
public:
    int trib(int n, vector<int> &dp) {
        if (dp[n] != -1) return dp[n];

        return dp[n] = trib(n-1, dp) + trib(n-2, dp) + trib(n-3, dp);
    }

    int tribonacci(int n) {
        vector<int> dp(38, -1);

        dp[0] = 0;
        dp[1] = dp[2] = 1;

        return trib(n, dp);
    }
};