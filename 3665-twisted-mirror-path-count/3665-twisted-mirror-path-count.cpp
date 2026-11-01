using ll = long long;
using vi = vector<ll>;
const int sz = 501, mod = 1e9+7;
ll dp[sz][sz][2];
vi dr = {0,1}, dc = {1,0};
class Solution {
public:
    int uniquePaths(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        memset(dp,0,sizeof(dp));
        dp[0][0][0] = 1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                for (int l=0; l<2; l++) {
                    if (a[i][j]) {
                        int nl = l ^ a[i][j];
                        int r = i + dr[nl];
                        int c = j + dc[nl];
                        if (r >= n || c >= m) continue;
                        dp[r][c][nl] += dp[i][j][l];
                        dp[r][c][nl] %= mod;
                    }
                    else {
                        for (int nl=0; nl<2; nl++) {
                            int r = i + dr[nl];
                            int c = j + dc[nl];
                            if (r >= n || c >= m) continue;
                            dp[r][c][nl] += dp[i][j][l];
                            dp[r][c][nl] %= mod;
                        }
                    }
                }
            }
        }
        auto &t = dp[n-1][m-1];
        return (t[0]+t[1]) % mod;
    }
};