using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1e9+7;

class Solution {
public:
    int numMusicPlaylists(int n, int m, int k) {
        vector dp(m+1, vvi(n+1, vi(k+1)));
        dp[0][0][0] = 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<=n; j++) {
                for (int l=0; l<=k; l++) {
                    ll nl = min(l+1,k); 
                    dp[i+1][j][nl] += (dp[i][j][l] * (j-l)) % mod;
                    dp[i+1][j][nl] %= mod;
                    dp[i+1][min(j+1,n)][nl] += (dp[i][j][l] * (n-j)) % mod;
                    dp[i+1][min(j+1,n)][nl] %= mod;
                }
            }
        }
        ll ans = 0;
        for (int l=0; l<=k; l++) {
            ans += dp[m][n][l];
            ans %= mod;
        }
        return ans;        
    }
};