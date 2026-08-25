#include <cstring>

class Solution {
public:
    int dp[1005];

    int ju(vector<int> &nums, int i) {
        int n = nums.size();

        if (i == n-1) return 0;

        if (dp[i] != -1) return dp[i];

        int res = INT_MAX;

        for (int j = 1; j <= nums[i]; j++) {
            if (i+j < n) {
                int sub = ju(nums, i + j);
                if (sub != INT_MAX) {
                    res = min(res, 1 + sub);
                }
            }
        }

        return dp[i] = res;
    }

    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));

        return ju(nums, 0);
    }
};
