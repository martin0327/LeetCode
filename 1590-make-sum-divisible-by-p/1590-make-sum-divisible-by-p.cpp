using ll = long long;
using vi = vector<ll>;
const ll inf = 1e9;

class Solution {
public:
    int minSubarray(vector<int>& a, int p) {
        ll n = a.size();
        ll s = accumulate(a.begin(), a.end(), 0ll);
        s %= p;
        if (s == 0) return 0;

        vi pre(n+1);
        for (ll i=1; i<=n; i++) {
            pre[i] = pre[i-1] + a[i-1];
            pre[i] %= p;
        }
        map<ll,ll> mp;
        ll ret = n;
        for (ll i=0; i<=n; i++) {
            ll t = pre[i] - s + p;
            t %= p;
            if (mp.count(t)) {
                ll j = mp[t];
                ret = min(ret, i-j);
            }
            mp[pre[i]] = i;
        }
        if (ret == n) ret = -1;
        return ret;
    }
};