class Solution {
public:
    int mySqrt(int x) {
        long long lo = 1, hi = x;

        while (lo <= hi) {
            long long mid = (lo+hi)/2ll;
            if (mid*mid == x) return mid;

            if (mid*mid > x) {
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }

        return (int)hi;
    }
};