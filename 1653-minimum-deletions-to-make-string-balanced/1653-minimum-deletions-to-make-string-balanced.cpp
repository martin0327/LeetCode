using ll = long long;
using vi = vector<ll>;
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vi a, b;
        for (int i=0; i<n; i++) {
            if (s[i] == 'a') a.push_back(i);
            else b.push_back(i);
        }
        ll lo = 0, hi = n, ans = -1;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            ll n = a.size();
            ll m = b.size();
            bool ok = (mid >= n || mid >= m);

            if (!ok) {
                for (ll c1=0; c1<=mid; c1++) {
                    ll c2 = mid - c1;
                    ll x = a[n-1-c1];
                    ll y = b[c2];
                    if (x <= y) ok = true;
                }
            }
            if (ok) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};