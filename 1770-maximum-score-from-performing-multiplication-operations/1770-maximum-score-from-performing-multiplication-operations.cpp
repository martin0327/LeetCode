using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:    
    int dp[1001][1001];
    int maximumScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        int m = a.size();
        for (int i=0; i<=n; i++) for (int j=0; j<=n; j++) dp[i][j] = -1e9;
        dp[0][0] = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; i+j<n; j++) {
              dp[i+1][j] = max(dp[i+1][j], dp[i][j] + a[i] * b[i+j]);
              dp[i][j+1] = max(dp[i][j+1], dp[i][j] + a[m-1-j] * b[i+j]);
            }
        }
        int ans = -1e9;
        for (int i=0; i<=n; i++) {
            ans = max(ans, dp[i][n-i]);
        }    
        return ans;
    }
};