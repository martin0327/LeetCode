using ll = long long;
const ll mod = 1e9+7;

class Solution {
public:
  ll dp[31][1001];
  int numRollsToTarget(int n, int k, int target) {
    dp[0][0] = 1;
    for (int i=0; i<n; i++) {
      for (int j=0; j<target; j++) {
        for (int l=1; l<=k; l++) {
          if (j+l <= target) {
            dp[i+1][j+l] += dp[i][j];
            dp[i+1][j+l] %= mod;
          }
        }
      }
    }
    return dp[n][target];
  }
};  