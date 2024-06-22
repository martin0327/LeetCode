using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1e9+7;

class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& req) {
        ll m = 0;
        vi a(n,-1);
        for (auto v : req) m = max(m, a[v[0]] = v[1]);

        vvi dp(n+1, vi(m+1));
        dp[0][0] = 1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<=m; j++) {
                if (dp[i][j] == 0) continue;
                for (int d=0; d<=i; d++) {
                    int nj = j + d;
                    if (nj > m) break;
                    dp[i+1][nj] += dp[i][j];
                    dp[i+1][nj] %= mod;
                }
            }

            if (a[i] != -1) {
                for (int j=0; j<=m; j++) {
                    if (j != a[i]) dp[i+1][j] = 0;
                }
            }
        }
        
        ll ans = 0;
        for (int j=0; j<=m; j++) {
            ans += dp[n][j];
            ans %= mod;
        }
        return ans;
    }
};