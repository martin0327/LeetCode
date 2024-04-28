using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

ll mod =  1e9+7;
ll safe_mod(ll x) {
    x %= mod;
    return (x<0) ? x+mod : x;
}
void mod_sum(ll &x, ll y) { x = safe_mod(x+y); }
ll mod_acc(vi &a) { return safe_mod(accumulate(a.begin(), a.end(),0ll)); }

vi dp[1001][1001];

class Solution {
public:
    
    int numberOfStableArrays(int n, int m, int lim) {
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=m; j++) dp[i][j] = {0,0};
        }

        for (int i=1; i<=min(n,lim); i++) dp[i][0][0] = 1;
        for (int j=1; j<=min(m,lim); j++) dp[0][j][1] = 1;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                mod_sum(dp[i][j][0], mod_acc(dp[i-1][j]));
                mod_sum(dp[i][j][1], mod_acc(dp[i][j-1]));
                if (i > lim) mod_sum(dp[i][j][0], -dp[i-lim-1][j][1]);
                if (j > lim) mod_sum(dp[i][j][1], -dp[i][j-lim-1][0]);
            }
        }
        return mod_acc(dp[n][m]);
    }
};