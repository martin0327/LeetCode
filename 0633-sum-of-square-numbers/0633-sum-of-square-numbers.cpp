using ll = long long;
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (ll i=0; i*i<=c; i++) {
            ll x = c - i*i;
            ll lo = 0, hi = x, y = -1;
            while (lo <= hi) {
                ll mid = (lo+hi)/2;
                if (mid*mid <= x) {
                    y = mid;
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
            if (y*y == x) return true;
        }
        return false;
    }
};