using ll = long long;
class Solution {
public:
    long long minimumCost(ll c1, ll c2, ll cb, ll n1, ll n2) {
        ll n = min(n1,n2);
        ll ans = n * min(c1+c2, cb);
        n1 -= n; n2 -= n;
        ans += n1 * min(c1,cb);
        ans += n2 * min(c2,cb);
        return ans;
    }
};