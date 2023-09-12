using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vp = vector<pii>;
const ll inf = 1e18;

class Solution {
public:
    int minTaps(int n, vector<int>& rg) {
        map<ll,vi> mp;
        for (int i=0; i<=n; i++) {
            ll l = i - rg[i], r = i + rg[i];
            l = max(l,0ll);
            r = min(r,(ll)n);
            mp[r].push_back(l);
        }
        vi dp(n+1, inf);
        dp[0] = 0;
        for (int i=1; i<=n; i++) {
            for (auto l : mp[i]) {
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