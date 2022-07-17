#define ll long long
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
const int mod = 1e9+7;

class Solution {
public:
    int kInversePairs(int n, int k) {
        vvi dp(n+1, vi(k+1));
        for (int i=0; i<=n; i++) dp[i][0] = 1;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=k; j++) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                dp[i][j] %= mod;
                if (j >= i) {
                    dp[i][j] += mod - dp[i-1][j-i];
                    dp[i][j] %= mod;
                }
            }
        }
        return dp[n][k];
    }  
};

#define ll int