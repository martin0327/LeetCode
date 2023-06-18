using ld = long double;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
using vs = vector<string>;
using vvs = vector<vs>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;
const ll mod = 1e9+7;

class Solution {
public:
    int specialPerm(vector<int>& a) {
        ll n = a.size();        

        vvi dp(1<<n, vi(n));
        for (int i=0; i<n; i++) {
            dp[1<<i][i] = 1;
        }
        for (int mask=0; mask<(1<<n); mask++) {
            for (int i=0; i<n; i++) {
                if (dp[mask][i] == 0) continue;
                for (int j=0; j<n; j++) {
                    if (mask>>j&1) continue;
                    if (a[i] % a[j] == 0 || a[j] % a[i] == 0) {
                        ll nmask = mask | (1<<j);
                        dp[nmask][j] += dp[mask][i];
                        dp[nmask][j] %= mod;
                    }
                }
            }
        }
        ll ans = 0;
        for (int i=0; i<n; i++) {
            ans += dp[(1<<n)-1][i];
            ans %= mod;
        }
        return ans;
    }
};