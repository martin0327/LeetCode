using vi = vector<int>;
using vvi = vector<vi>;
const int inf = 1e9;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        vvi dp(n, vi(n,inf));
        for (int j=0; j<n; j++) dp[0][j] = a[0][j];
        for (int i=1; i<n; i++) {
            for (int j=0; j<n; j++) {
                for (int l=0; l<n; l++) {
                    if (j==l) continue;
                    dp[i][j] = min(dp[i][j], dp[i-1][l] + a[i][j]);
                }
            }
        }
        int ans = inf;
        for (int j=0; j<n; j++) ans = min(ans, dp[n-1][j]);
        return ans;
    }
};