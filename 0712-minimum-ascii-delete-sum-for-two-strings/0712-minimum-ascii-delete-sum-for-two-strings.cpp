using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
void chmax(ll &x, ll y) {x = max(x,y);}

class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        ll n = s.size(), m = t.size();
        ll tot = 0;
        for (auto c : s) tot += (ll) c;
        for (auto c : t) tot += (ll) c;
        vvi dp(n+1, vi(m+1));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (s[i]==t[j]) chmax(dp[i+1][j+1],dp[i][j]+(ll)s[i]);
                chmax(dp[i+1][j+1],dp[i][j+1]);
                chmax(dp[i+1][j+1],dp[i+1][j]);
            }
        }
        ll ans = tot - 2*dp[n][m];
        return ans;
    }
};