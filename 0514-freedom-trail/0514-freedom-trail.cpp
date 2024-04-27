using vi = vector<int>;
using vvi = vector<vi>;
const int inf = 1e9;

class Solution {
public:
    int findRotateSteps(string t, string s) {
        int n = s.size(), m = t.size();
        vvi dp(n+1, vi(m,inf));
        dp[0][0] = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (dp[i][j] == inf) continue;
                for (int nj=0; nj<m; nj++) {
                    if (s[i] != t[nj]) continue;
                    int d = abs(j-nj);
                    d = min(d, m-d);
                    dp[i+1][nj] = min(dp[i+1][nj], dp[i][j] + d + 1);
                }
            }
        }
        int ans = inf;
        for (int j=0; j<m; j++) ans = min(ans, dp[n][j]);
        return ans;
    }
};