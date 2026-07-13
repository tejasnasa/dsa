class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxval = nums[0], curval = 0;

        for (int n: nums) {
            if (curval < 0) {
                curval = 0;
            }
            curval += n;
            maxval = max(maxval, curval);
        }

        return maxval;
    }
};
