/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int t, MountainArray &ma) {
        int n = ma.length();
        int l = 1, r = n-2;
        while (r-l >= 3) {
            int m1 = l+(r-l)/3;
            int m2 = r-(r-l)/3;
            int f1 = ma.get(m1);      
            int f2 = ma.get(m2);
            if (f1 < f2) l = m1;
            else r = m2;
        }
        int mx = -1, idx = -1;
        for (int i=l; i<=r; i++) {
            int x = ma.get(i);
            if (x > mx) {
                mx = x;
                idx = i;
            }
        }
        
        if (mx == t) return idx;
        {
            int lo = 0, hi = idx-1;
            while (lo <= hi) {
                int mid = (lo+hi)/2;
                int x = ma.get(mid);
                if (x==t) return mid;
                if (x < t) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        {
            int lo = idx+1, hi = n-1;
            while (lo <= hi) {
                int mid = (lo+hi)/2;
                int x = ma.get(mid);
                if (x==t) return mid;
                if (x < t) hi = mid - 1;
                else lo = mid + 1;
            }
        }
        
        return -1;
    }
};