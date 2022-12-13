using vi = vector<int>;
using vvi = vector<vi>;
const int inf = 1e9;

class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& a) {
    int n = a.size();
    vvi dp(n, vi(n, inf));
    for (int j=0; j<n; j++) dp[0][j] = a[0][j];
    for (int i=0; i<n-1; i++) {
      for (int j=0; j<n; j++) {
        for (int k=-1; k<=1; k++) {
          int nj = j + k;
          if (nj < 0 || nj >= n) continue;
          dp[i+1][nj] = min(dp[i+1][nj], dp[i][j] + a[i+1][nj]);
        }
      }
    }
    int ans = inf;
    for (int j=0; j<n; j++) ans = min(ans, dp[n-1][j]);
    return ans;
  }
};  