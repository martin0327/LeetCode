using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll lim = 2e10;
class Solution {
public:
    int numDistinct(string s, string t) {
        ll n = s.size(), m = t.size();
        vvi dp(n+1, vi(m+1));
        dp[0][0] = 1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (i > 0 && dp[i-1][j] < lim) dp[i][j] += dp[i-1][j];
                if (dp[i][j] == 0) continue;
                if (s[i] == t[j]) {
                    dp[i+1][j+1] += dp[i][j];
                }
            }
        }
        ll ans = 0;
        for (int i=0; i<=n; i++) {
            ans += dp[i][m];
        }
        return ans;
    }
};