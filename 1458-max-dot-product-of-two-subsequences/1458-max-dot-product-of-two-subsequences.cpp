using vi = vector<int>;
using vvi = vector<vi>;
const int inf = 1e9;
class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vvi dp(n, vi(m,-inf));
        dp[0][0] = a[0]*b[0];
        for (int i=1; i<n; i++) dp[i][0] = max(dp[i-1][0],a[i]*b[0]);
        for (int j=1; j<m; j++) dp[0][j] = max(dp[0][j-1],a[0]*b[j]);
        for (int i=1; i<n; i++) {
            for (int j=1; j<m; j++) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i]*b[j]);
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
                dp[i][j] = max(dp[i][j], a[i]*b[j]);
            }
        }
        return dp[n-1][m-1];        
    }
};