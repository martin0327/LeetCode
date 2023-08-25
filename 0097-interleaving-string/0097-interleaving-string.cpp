class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int n = s1.size();
    int m = s2.size();
    int k = s3.size();
    if (k != n+m) return false;
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    s3 = ' ' + s3;
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    dp[0][0] = 1;
    for (int i=0; i<=n; i++) {
      for (int j=0; j<=m; j++) {
        if (i+j+1 > k) continue;
        if (i+1 <= n && s3[i+j+1] == s1[i+1]) dp[i+1][j] |= dp[i][j];
        if (j+1 <= m && s3[i+j+1] == s2[j+1]) dp[i][j+1] |= dp[i][j];
      }
    }
    return dp[n][m];
  }
};