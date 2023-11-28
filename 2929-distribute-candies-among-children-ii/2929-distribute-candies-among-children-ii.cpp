using ll = long long;

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        ll ans = 0, lim = limit;
        for (int i=0; i<=min(n,limit); i++) {
            ll m = n - i, lj = max(0ll,m-lim), rj = min(m,lim);
            ans += max(0ll, rj-lj+1);
        }
        return ans;
    }
};