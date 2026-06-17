class Solution {
public:
    int binary_search(int l, int r, vector<int>& nums, int target) {
        if (l > r) return -1;
        int m = l + (r-l)/2;

        if (nums[m] > target) {
            return binary_search(l,m-1,nums,target);
        } else if (nums[m] < target) {
            return binary_search(m+1,r,nums,target);
        } else {
            return m;
        }
    }

    int search(vector<int>& nums, int target) {
        return binary_search(0,nums.size(),nums,target);
    }
};
