using ll = long long;
using vi = vector<ll>;
void chmax(ll &x, ll y) {x = max(x,y);}

class Solution {
public:
    int maxScore(vector<int>& a) {
        ll n = a.size();
        vi dp(1<<n);
        for (int mask=0; mask<(1<<n); mask++) {
            ll cnt = __builtin_popcount(mask);
            cnt = (cnt/2) + 1;
            for (int i=0; i<n; i++) {
                if (mask>>i&1) continue;
                for (int j=i+1; j<n; j++) {
                    if (mask>>j&1) continue;
                    ll nmask = mask | (1<<i) | (1<<j);
                    chmax(dp[nmask],dp[mask] + cnt * gcd(a[i],a[j]));
                }
            }
        }
        return dp[(1<<n)-1];
    }
};