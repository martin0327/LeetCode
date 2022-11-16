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
        int lo = 1;
        int hi = n;
        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            int x = guess(mid);
            if (x==0) return mid;
            if (x==-1) hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }
};  