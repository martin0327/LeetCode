using ll = long long;
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        ll m = 2*n, ans = 0;
        for (ll x=1; x*x <= m; x++) {
            if (m % x == 0) {
                auto y = m / x;
                if (x < y) {
                    if ((x+y) % 2) {
                        auto r = (x+y-1) / 2;
                        auto l = (y-x+1) / 2;
                        if (l <= r) ans++;
                    }
                }
            }
        }
        return ans;
    }
};

// l + ... + r = (r-l+1) * (r+l) / 2 = n

// (r-l+1) * (r+l) = 2 *

// let m = 2*n = x * y
// x < y
// x + y = 2*r + 1
// y - x = 2*l - 1
// l <= r