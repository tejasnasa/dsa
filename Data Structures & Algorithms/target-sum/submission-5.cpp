#include <cstring>

class Solution {
public:
    int dp[21][20002];

    int ways(vector<int> &nums, int n, int sum) {
    if (sum < 0) return 0;
    if (n == 0) return (sum == 0) ? 1 : 0;
    if (dp[n][sum] != -1) return dp[n][sum];

    if (sum >= nums[n-1]) {
        return dp[n][sum] = ways(nums, n-1, sum-nums[n-1]) + ways(nums, n-1, sum);
    } else {
        return dp[n][sum] = ways(nums, n-1, sum);
    }
}

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        
        int sum = 0;
        for (auto n: nums) sum += n;

        if (target > sum || target < -sum) return 0;
        if ((sum+target)%2 != 0) return 0;

        return ways(nums, nums.size(), (sum+target)/2);
    }
};
