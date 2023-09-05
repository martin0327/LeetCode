using vi = vector<int>;
using vvi = vector<vi>;
const int inf = 1e9;
class Solution {
public:
    int minimumOperations(string s) {
        int n = s.size(), m = 25;
        vvi dp(n+1, vi(m,inf));
        dp[0][0] = 0;
        for (int i=0; i<n; i++) {
            int x = s[i] - '0';
            for (int j=0; j<m; j++) {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
                int nj = ((10*j)+x)%m;
                dp[i+1][nj] = min(dp[i+1][nj], dp[i][j]);
            }
        }
        return dp[n][0];         
    }
};