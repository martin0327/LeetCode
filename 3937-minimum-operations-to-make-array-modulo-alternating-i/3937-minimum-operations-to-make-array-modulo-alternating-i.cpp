using ll = long long;
const ll inf = 2e18;

class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        ll n = a.size();
        map<ll,ll> odd, even;
        ll sz1 = 0, sz2 = 0;
        for (int i=0; i<n; i++) {
            ll x = a[i];
            x %= k;
            if (i&1) {
                odd[x]++;
                sz1++;
            }
            else {
                even[x]++;
                sz2++;
            }
        }
        ll ans = inf;
        for (int x=0; x<k; x++) {
            for (int y=0; y<k; y++){
                if (x == y) continue;
                ll t = 0;
                for (auto [key,val] : odd) {
                    if (key == x) continue;
                    ll d = abs(x-key);
                    d = min(d, k-d);
                    t += val * d;

                }
                for (auto [key,val] : even) {
                    if (key == y) continue;
                    ll d = abs(y-key);
                    d = min(d,k-d);
                    t += val * d;
                }
                ans = min(ans, t);
            }
        }
        return ans;
    }
};