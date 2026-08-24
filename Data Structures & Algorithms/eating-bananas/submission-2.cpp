class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        sort(piles.begin(), piles.end());
        int lo = 1, hi = piles.back();
        int res = hi;

        while (lo <= hi) {
            int mid = (lo+hi)/2;
            int val = 0;

            for (int j = 0; j < piles.size(); j++) {
                val += ((piles[j] + mid - 1) / mid);
            }

            if (val <= h) {
                res = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }

        return res;
    }
};
