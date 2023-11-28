using ll = long long;
using vi = vector<ll>;

void debug(vector<ll> &a) {
    for (auto x : a) {
        cout << x << " ";
    }   cout << endl;
}
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        ll ans = 0, lim = limit;
        for (int i=0; i<=lim; i++) {
            ll m = n - i;
            if (m < 0) continue;
            ll lj = max(0ll,m-lim), rj = min(m,lim);
            // ll lj = -1, rj = -1;
            // {
            //     ll lo = 0, hi = min(m,lim);
            //     while (lo <= hi) {
            //         ll mid = (lo+hi)/2;
            //         ll k = m - mid;
            //         if (k <= lim) {
            //             lj = mid;
            //             hi = mid - 1;
            //         } 
            //         else lo = mid + 1;
            //     }
            // }
            // {
            //     ll lo = 0, hi = min(m,lim);
            //     while (lo <= hi) {
            //         ll mid = (lo+hi)/2;
            //         ll k = m - mid;
            //         if (0 <= k) {
            //             rj = mid;
            //             lo = mid + 1;
            //         }
            //         else hi = mid - 1;
            //     }
            // }
            if (lj != -1 && rj != -1) {
                ans += max(0ll, rj-lj+1);
            }
        }
        return ans;
    }
};