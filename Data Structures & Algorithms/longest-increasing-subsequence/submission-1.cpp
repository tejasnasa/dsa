#include <cstring>

class Solution {
public:
    int dp[1005];

    int lis(vector<int> &nums, int n) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];

        int best = 1;
        for (int i = 0; i < n-1; i++) {
            if (nums[i] < nums[n-1]) {
                best = max(best, 1+lis(nums,i+1));
            }
        }

        return dp[n] = best;
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1 , sizeof(dp));

        int ans = 0;
        for (int n = 1; n <= (int)nums.size(); n++)
            ans = max(ans, lis(nums, n));
        return ans;

    }
};
