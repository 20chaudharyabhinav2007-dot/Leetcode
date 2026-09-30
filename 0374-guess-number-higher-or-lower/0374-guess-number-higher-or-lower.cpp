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
        long long low = 1;
        long long high = n;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            int x = guess(mid);
            if (x == 0)
                return mid;
            if (x == 1)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};