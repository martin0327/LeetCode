using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vp = vector<pii>;
const ll inf = 2e18;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& a, int k) {
        ll n = a.size();
        vvi w(n+1, vi(n+1)), h(n+1, vi(n+1));
        for (int i=0; i<n; i++) {
            int s = 0, mx = 0;
            for (int j=i; j<n; j++) {
                s += a[j][0];
                mx = max(mx, a[j][1]);
                w[i+1][j+1] = s;
                h[i+1][j+1] = mx;
            }
        }
        vi dp(n+1, inf);
        dp[0] = 0;
        for (int j=1; j<=n; j++) {
            for (int i=1; i<=j; i++) {
                if (w[i][j] <= k) {
                    dp[j] = min(dp[j], dp[i-1] + h[i][j]);
                }
            }
        }
        return dp[n];
    }
};