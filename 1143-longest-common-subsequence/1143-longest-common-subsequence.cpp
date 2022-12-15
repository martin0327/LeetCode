class Solution {
public:
  int dp[1001][1001];
  int longestCommonSubsequence(string s, string t) {
    int n = s.size(), m = t.size();
    int ans = 0;
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=m; j++) {
        dp[i][j] = max({dp[i-1][j], dp[i][j-1], s[i-1]==t[j-1] ? dp[i-1][j-1]+1 : 0});
      }
    }
    return dp[n][m];
  }
};    