using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

ll mod =  1e9+7;
ll safe_mod(ll x) {
    x %= mod;
    return (x<0) ? x+mod : x;
}
ll mod_sum(ll x, ll y) { return safe_mod(x+y); }
ll acc_sum(vi &a) { 
    ll ret = 0;
    for (auto x : a) ret = mod_sum(ret, x);
    return ret;
}

vi dp[1001][1001];
class Solution {
public:
    
    int numberOfStableArrays(int n, int m, int lim) {
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=m; j++) {
                dp[i][j] = {0,0};
            }
        }
        // vvvi dp(n+1, vvi(m+1, vi(2)));
        for (int i=1; i<=min(n,lim); i++) dp[i][0][0] = 1;
        for (int j=1; j<=min(m,lim); j++) dp[0][j][1] = 1;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (i > 0) dp[i][j][0] = mod_sum(dp[i][j][0], acc_sum(dp[i-1][j]));
                if (j > 0) dp[i][j][1] = mod_sum(dp[i][j][1], acc_sum(dp[i][j-1]));
                if (i > lim) dp[i][j][0] = mod_sum(dp[i][j][0], -dp[i-lim-1][j][1]);
                if (j > lim) dp[i][j][1] = mod_sum(dp[i][j][1], -dp[i][j-lim-1][0]);
            }
        }
        return acc_sum(dp[n][m]);
    }
};