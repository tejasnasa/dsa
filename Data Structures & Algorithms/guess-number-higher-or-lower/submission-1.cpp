/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lo = 0, hi = n-1, mid;
        
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            int pick = guess(mid);

            if (pick > 0) hi = mid - 1;
            else if (pick < 0) lo = mid + 1;
            else return mid;
        }
    }
};