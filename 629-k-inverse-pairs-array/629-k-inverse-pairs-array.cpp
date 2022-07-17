using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
const ll mod = 1e9+7;

class Solution {
public:
    int kInversePairs(int n, int k) {
        vvi dp(n+1, vi(k+1));
        dp[0][0] = 1;
        for (int i=1; i<=n; i++) {
            ll temp = 0;
            for (int j=0; j<=k; j++) {
                temp += dp[i-1][j];
                temp %= mod;
                if (j >= i) {
                    temp += mod - dp[i-1][j-i];
                    temp %= mod;
                }
                dp[i][j] = temp;
            }
        }
        return dp[n][k];
    }  
};