using ll = long long;
using vi = vector<ll>;

class Solution {
public:
    long long minimumSteps(string s) {
        ll n = s.size();
        vi a(n);
        for (int i=0; i<n; i++) {
            a[i] = (s[i]=='1');
        }
        a.insert(a.begin(), 0ll);
        vi pre(n+1);
        for (int i=1; i<=n; i++) pre[i] = pre[i-1] + a[i];
        ll ans = 0;
        for (int i=1; i<=n; i++) {
            if (!a[i]) ans += pre[i];
        }
        return ans;        
    }
};