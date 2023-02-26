template<typename T> void chmin(T &x, T y) {x = min(x,y);}
using vi = vector<int>;
using vvi = vector<vi>;
const int inf = 1e9;

class Solution {
public:
  int minDistance(string s, string t) {
    int n = s.size(), m = t.size();
    vvi dp(n+1, vi(m+1,inf));
    dp[0][0] = 0;
    for (int i=0; i<=n; i++) {
      for (int j=0; j<=m; j++) {
        if (i) chmin(dp[i][j], dp[i-1][j]+1);
        if (j) chmin(dp[i][j], dp[i][j-1]+1);
        if (i&&j) chmin(dp[i][j], dp[i-1][j-1]+(s[i-1]!=t[j-1]));
      }
    }
    return dp[n][m];
  }
};