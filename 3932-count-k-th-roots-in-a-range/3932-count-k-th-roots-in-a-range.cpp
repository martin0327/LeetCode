using ll = long long;
ll int_pow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res *= base;
        exp >>= 1;
        base *= base;
    }
    return res;
}
class Solution {
public:
    int countKthRoots(ll l, ll r, ll k) {
        if (k == 1) return r-l+1;
        ll sz = 1e5, ans = 0;
        for (int i=0; i<sz; i++) {
            ll x = int_pow(i,k);
            if (x > r) break;
            if (l <= x) ans++;
        }
        return ans;
    }
};