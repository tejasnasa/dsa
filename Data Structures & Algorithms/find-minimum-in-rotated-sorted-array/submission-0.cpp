class Solution {
public:
    int findMin(vector<int> &nums) {
        int lo = 0, hi = nums.size()-1, ans = INT_MAX;

        while (lo <= hi) {
            int mid = (lo+hi)/2;

            // one side is always sorted

            // check for left half
            if (nums[lo] <= nums[mid]) {
                // find smallest of sorted half
                ans = min(ans, nums[lo]);
                // go to unsorted half
                lo = mid+1;
            } 
            
            // check for right half
            else {
                // find smallest of sorted half
                ans = min(ans, nums[mid]);
                // go to unsorted half
                hi = mid-1;
            }
        }

        return ans;
    }
};
