using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<ll>;

class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        string ae = "aeiou";
        set<char> sc(ae.begin(), ae.end());
        int n = s.size();
        vi a(n+1), pre(n+1);
        for (int i=0; i<n; i++) a[i+1] = (sc.count(s[i])) ? 1 : -1;
        for (int i=1; i<=n; i++) pre[i] = pre[i-1] + a[i];
        ll m = 1;
        {
            int x = k;
            for (int i=2; i<=k; i++) {
                int cnt = 0;
                while (x % i == 0) {
                    x /= i;
                    cnt++;
                }
                cnt = (cnt+1)/2;
                while (cnt--) m *= i;
            }
        }
        m *= 2;
        map<pii,ll> mp;
        ll ans = 0;
        for (int i=0; i<=n; i++) {
            pii t = {i%m,pre[i]};
            ans += mp[t];
            mp[t]++;
        } 
        return ans;
    }
}; 