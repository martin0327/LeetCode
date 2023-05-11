using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
class Solution {
public:
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vvi dp(n+1, vi(m+1));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+(a[i-1]==b[j-1]));
            }
        }
        return dp[n][m];
    }
};