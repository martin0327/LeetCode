using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll inf = 1e18;

class Solution {
public:
    int minTaps(int n, vector<int>& rg) {
        vvi a(n+1);
        for (int i=0; i<=n; i++) {
            ll l = i - rg[i], r = i + rg[i];
            l = max(l,0ll);
            r = min(r,(ll)n);
            a[r].push_back(l);
        }
        vi dp(n+1, inf);
        dp[0] = 0;
        for (int i=1; i<=n; i++) {
            for (auto l : a[i]) {
                for (int j=l; j<i; j++) {
                    dp[i] = min(dp[i],dp[j]+1);
                }
            }
        }
        ll ans = dp[n];
        if (ans==inf) ans = -1;
        return ans;
    }
};