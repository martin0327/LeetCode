using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
void chmax(ll &x, ll y) {x = max(x,y);}
void chmin(ll &x, ll y) {x = min(x,y);}

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());

        vvi dp(n+1, vi(n+1));
        for (int i=1; i<=n; i++) {
            for (int j=1; i+j<=n; j++) {
                chmax(dp[i][j], max(dp[i-1][j],dp[i][j-1]));
                chmax(dp[i][j], dp[i-1][j-1]+(s[i-1]==t[j-1]));
            }
        }
        
        ll ans = 1e9;
        for (int i=0; i<=n; i++) {
            chmin(ans, n-2*dp[i][n-i]);
            if (i<=n-1) chmin(ans, (n-1-2*dp[i][n-1-i]));
        }        
        return ans;
    }
};  