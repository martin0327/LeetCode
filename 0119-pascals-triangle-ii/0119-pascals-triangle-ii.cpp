using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    vector<int> getRow(int n) {
        vvi dp(n+1, vi(n+1));
        dp[0][0] = 1;
        for (int i=1; i<=n; i++) {
            for (int j=0; j<=i; j++) {
                dp[i][j] = dp[i-1][j] + ((j>0) ? dp[i-1][j-1] : 0);
            }
        }
        return dp[n];
    }
};