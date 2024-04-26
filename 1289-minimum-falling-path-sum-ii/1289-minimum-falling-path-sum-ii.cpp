using vi = vector<int>;
using vvi = vector<vi>;
const int inf = 1e9;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        vvi dp(n, vi(n,inf));
        vi pre(n), suf(n);
        for (int j=0; j<n; j++) dp[0][j] = a[0][j];
        for (int i=1; i<n; i++) {
            pre[0] = dp[i-1][0];
            for (int j=1; j<n; j++) pre[j] = min(pre[j-1], dp[i-1][j]);
            suf[n-1] = dp[i-1][n-1];
            for (int j=n-2; j>=0; j--) suf[j] = min(suf[j+1], dp[i-1][j]);
            auto p = [&] (int j) { return (j>=0) ? pre[j] : inf; };
            auto s = [&] (int j) { return (j<n) ? suf[j] : inf; };
            for (int j=0; j<n; j++) {    
                dp[i][j] = a[i][j] + min(p(j-1),s(j+1));
            }
        }
        int ans = inf;
        for (int j=0; j<n; j++) ans = min(ans, dp[n-1][j]);
        return ans;
    }
};