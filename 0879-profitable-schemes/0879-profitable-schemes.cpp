using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1e9+7;

class Solution {
public:
    int profitableSchemes(int n, int m, vector<int>& a, vector<int>& b) {
        vvi dp(n+1, vi(m+1));
        dp[0][0] = 1;
        int sz = a.size();
        for (int k=0; k<sz; k++) {
            for (int i=n-a[k]; i>=0; i--) {
                int ni = i + a[k];
                for (int j=m; j>=0; j--) {
                    int nj = min(m,j+b[k]);
                    dp[ni][nj] += dp[i][j];
                    dp[ni][nj] %= mod; 
                }
            }
        }
        ll ans = 0;
        for (int i=0; i<=n; i++) ans += dp[i][m];
        return ans % mod;
    }
};