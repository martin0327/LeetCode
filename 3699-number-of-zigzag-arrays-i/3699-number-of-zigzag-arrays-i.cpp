using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
ll sm(ll x) { 
    x %= mod;
    if (x < 0) x += mod;
    return x;
}
ll mod_sum(ll x, ll y) { return sm(x+y); }
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        ll sz = r-l+1;
        vi a(sz,1), b(sz,1);
        for (int i=0; i+1<n; i++) {
            vi ta(sz), tb(sz);
            for (int j=1; j<sz; j++) {
                ta[j] = mod_sum(ta[j-1],b[j-1]);
            }
            for (int j=sz-2; j>=0; j--) {
                tb[j] = mod_sum(tb[j+1],a[j+1]);
            }
            swap(a,ta);
            swap(b,tb);
        }
        ll ans = 0;
        for (int j=0; j<sz; j++) {
            ans = mod_sum(ans, a[j]+b[j]);
        }
        return ans;
    }
};