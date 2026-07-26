#include <cstring>

class Solution {
public:
    int dp[102];

    int func(vector<int> &nums, int i, int n) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        return dp[i] = max(func(nums,i+1,n), nums[i] + func(nums,i+2,n));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        memset(dp, -1, sizeof(dp));
        int a = func(nums, 0, n-1);

        memset(dp, -1, sizeof(dp));
        int b = func(nums, 1, n);
        return max(a,b);
    }
};