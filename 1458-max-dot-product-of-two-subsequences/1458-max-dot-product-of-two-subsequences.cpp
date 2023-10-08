using vi = vector<int>;
using vvi = vector<vi>;
const int inf = 1e9;
class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vvi dp(n+1, vi(m+1,-inf));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                dp[i][j] = max({
                    a[i-1]*b[j-1],
                    dp[i-1][j-1] + a[i-1]*b[j-1],
                    dp[i-1][j-1],
                    dp[i-1][j],
                    dp[i][j-1]
                });
            }
        }
        return dp[n][m];        
    }
};