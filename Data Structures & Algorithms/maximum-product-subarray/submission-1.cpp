class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], minv = nums[0], maxv = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(maxv,minv);
            }
            maxv = max(nums[i], nums[i]*maxv);
            minv = min(nums[i], nums[i]*minv);
            res = max(res, maxv);
        }

        return res;
    }
};
