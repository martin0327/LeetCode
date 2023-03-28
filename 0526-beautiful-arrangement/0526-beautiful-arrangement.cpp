using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
  int countArrangement(int n) {
    vvi dp(n+1, vi(1<<n));
    dp[0][0] = 1;
    for (int i=0; i<n; i++) {
      for (int mask=0; mask<(1<<n); mask++) {
        if (!dp[i][mask]) continue;
        for (int j=0; j<n; j++) {
          if (mask>>j&1) continue;
          if ((i+1) % (j+1) && (j+1) % (i+1)) continue;
          dp[i+1][mask | (1<<j)] += dp[i][mask];
        }
      }
    }
    return dp[n][(1<<n)-1];
  }
};