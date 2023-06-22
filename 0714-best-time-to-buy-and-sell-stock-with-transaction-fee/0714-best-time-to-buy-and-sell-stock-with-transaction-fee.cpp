using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll inf = 1e18;
void chmax(ll &x, ll y) {x = max(x,y);}

class Solution {
public:
    int maxProfit(vector<int>& a, int k) {
        ll n = a.size();
        vvi dp(n+1, vi(2,-inf));
        dp[0][0] = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<2; j++) {
                chmax(dp[i+1][j],dp[i][j]);
                chmax(dp[i+1][j^1], (j==0 ? dp[i][j] - a[i] : dp[i][j] + a[i] - k));
            }
        }
        ll ans = max(dp[n][0],dp[n][1]);
        return ans;
    }
};