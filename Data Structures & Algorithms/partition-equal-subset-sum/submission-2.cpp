#include <cstring>

class Solution {
public:
    int dp[102][5010];

    bool part(vector<int> &nums, int n, int sum) {
        if (n == 0) return false;
        if (sum == 0) return true;
        if (dp[n][sum] != -1) return dp[n][sum];

        if (sum >= nums[n-1]) {
            return dp[n][sum] = part(nums, n-1, sum-nums[n-1]) || part(nums, n-1, sum);
        } else {
            return dp[n][sum] = part(nums, n-1, sum);
        }
    }

    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int sum = 0;
        for (auto n: nums) sum += n;

        if (sum % 2 != 0) return false;
        else return part(nums, nums.size(), sum/2);
    }
};
