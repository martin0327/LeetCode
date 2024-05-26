using ll = long long;
const ll mod = 1e9+7;

void mod_sum(ll &x, ll y) {
    x += y;
    x %= mod;
}

class Solution {
public:
    ll dp[100001][2][3];
    int checkRecord(int n) {
        dp[0][0][0] = 1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<2; j++) {
                for (int k=0; k<3; k++) {
                    if (j==0) mod_sum(dp[i+1][j+1][0], dp[i][j][k]);
                    if (k < 2) mod_sum(dp[i+1][j][k+1], dp[i][j][k]);
                    mod_sum(dp[i+1][j][0], dp[i][j][k]);
                }
            }
        }
        ll ans = 0;
        for (int j=0; j<2; j++) {
            for (int k=0; k<3; k++) {
                mod_sum(ans, dp[n][j][k]);
            }
        }
        return ans;
    }
};