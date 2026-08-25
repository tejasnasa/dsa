class Solution {
public:
    bool canShip(vector<int> &weights, int wei, int days) {
        int ships = 1, currCap = wei;
        for (int w: weights) {
            if (currCap - w < 0) {
                ships++;
                if (ships > days) return false;
                currCap = wei;
            }
            currCap -= w;
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        int res = hi;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (canShip(weights, mid, days)) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return res;
    }
};